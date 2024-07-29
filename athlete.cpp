//athlete.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This file holds the class definitions for the athlete class. Thes functions use overloaded operators to compare the athlete's name with strings, add
//medals to the medals list, and display the athlete stats. 

#include "athlete.h"
using namespace std;


//default constructor
athlete::athlete() : name(nullptr), sport("")
{

}



//destructor
athlete::~athlete()
{
	delete[] name; //deallocates memory
	name = nullptr;
}



//copy constructor
athlete::athlete(const athlete & obj) : name(nullptr),sport(obj.sport), medals(obj.medals)
{
	if(obj.name) //if athlete being copied from has a name
	{
		name = new char[strlen(obj.name) + 1]; //allocates correct memory
		strcpy(name, obj.name); //copies name
	};
}



//assignment operator
athlete & athlete::operator = (const athlete & og_athlete)
{
	if(this == &og_athlete) return *this; //check for self assignment

	if(name) delete[] name; //If name has value, deallocate memory

	name = new char[strlen(og_athlete.name) + 1]; //allocate correct memory
	strcpy(name, og_athlete.name); //copies name
	
	sport = og_athlete.sport; //sets sport string
	medals = og_athlete.medals; //sets medals vector

	return *this;
}



//equality operator, compares string to name
bool operator == (const athlete & op1, const string & op2)
{
	return(strcmp(op1.name, op2.c_str())) == 0;
}



//equality operator, compares string to name
bool operator == (const string & op1, const athlete & op2)
{
	return(strcmp(op1.c_str(), op2.name)) == 0;
}



//inequality operator, compares string to name
bool operator != (const athlete & op1, const string & op2)
{
	return(strcmp(op1.name, op2.c_str())) != 0;
}



//inequality operator, compares string to name
bool operator != (const string & op1, const athlete & op2)
{
	return(strcmp(op1.c_str(), op2.name)) != 0;
}



//addition assignment operator
athlete & athlete::operator += (int medal)
{
	if(medal < 1 || medal > 3)
	{
		bad_input error;
		throw error;
	}

	medals.push_back(medal); //Adds medal to back of list of medals

	return *this;
}



//addition operator (friend)
athlete operator + (const athlete & op1, int medal)
{
	if(medal < 1 || medal > 3)
	{
		bad_input error;
		throw error;
	}

	athlete temp = op1; //Create temp athlete object and set it to athlete obj passed in

	temp += medal; //Add medal to athlete's list of medals using previously overloaded += operand

	return temp;
}



//addition operator (friend)
athlete operator + (int medal, const athlete & op2)
{
	if(medal < 1 || medal > 3)
	{
		bad_input error;
		throw error;
	}

	athlete temp = op2; //Create temp athlete object and set it to athlete obj passed in

	temp += medal; //Add medal to athlete's list of medals using previously overloaded += operand

	return temp;
}



// >> operator, sets athletes name dynamically
istream & operator>>(istream & in, athlete & op2)
{
	string temp; //String to emporarily hold input

	if(op2.name) //If there is already a name
	{
		over_write  error; //Create error object
		throw error; //Throw error
		delete[] op2.name; //Delete current name so it can be reallocated
		op2.name = nullptr; //set name to null
	}

	in >> temp; //store input in temporary string

	op2.name = new char[temp.size() + 1]; //allocate correct space
	strcpy(op2.name, temp.c_str()); //set name with string
	
	return in; //Return instream operand
}



// << operator, output/display
ostream & operator << (ostream & out, const athlete & op2)
{
	if(!op2.name || op2.sport.empty()) //If there is no name or sport, throw error
	{
		no_data error;
		throw error;
	}

	//Outputs athlete details
	out << "Athlete: " << op2.name << "   Sport: " << op2.sport << "   This season's medals: ";

	for (auto it = op2.medals.begin(); it != op2.medals.end(); ++it) //Iterate through each medal in medals list
	{
		if(it != op2.medals.begin()) out << ", "; //Seperates the medals by commas w/o puting a comma before the 1st medal

		out << *it; //Displays medal at current element
	}

	return out; //Returns ostream operand
}



//Returns medals ranking score
float athlete::calc_medals_score(float weight) const
{
	float score = 0; //holds score to be returned

	for(const int & medal : medals) //Loops through each medal in medals
	{
		try
		{
			//Adds points to score, more points for higher placement
			if(medal == 1) score += 3 * weight;
			else if(medal == 2) score += 2 * weight;
			else if (medal == 3) score += 1 * weight;
		}
		catch (const bad_input & error)
		{
			cout << error.detail << endl;
		}
	}

	return score; //returns score
}



//Sets athlete's stats from user input
void athlete::input_athlete_stats(string sp)
{
	int entering = 0;

	if(name || !sport.empty()) //If the athlete's name or sport are already set
	{
		over_write error;
		throw error;
	}

	sport = sp; //Set athlete's sport with sport passed in

	cout << "\nEnter the athlete's name: ";
	cin >> *this; //Set's althlete's name using this objects overloaded >> operator 
	cout << "You enterd: " << name << endl;

	cout << "\nWould you like to enter any medals the athlete won this season?";
	entering = yes_or_no();

	while(entering)
	{
		*this += medal_from_user(); //Gets medal from user an adds it to medals list using overloaded += operator

		cout << "\nWould you like to enter another medal the athlete won this season?";
		entering = yes_or_no();
	}

	return;
};



//Get's yes or no from user, 1 for yes 0 for no
int athlete::yes_or_no(void) const
{
	int answer = 0;

	cout << "\nEnter you answer as an integer. \n1) yes\n2) no\nEnter: ";
	cin >> answer;

	while(answer != 1 && answer != 2)
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Invalid entry. Enter your answer as an integer.\n1) yes\n2) no\nEnter: ";
		cin >> answer;
	}

	if (answer == 1) return 1;

	return 0;
}



//Returns user's medal entery
int athlete::medal_from_user(void) const
{
	int medal = 0;
	cout << "\nEnter the athlete's medal as an integer, 1 for gold, etc..\nEnter: ";
	cin >> medal;

	while(medal != 1 && medal != 2 && medal != 3)
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');
		
		cout << "Invalid entry. Enter 1, 2, or 3.\nEnter: ";
		cin >> medal;
	}

	return medal;
}



//Checks if athlete's name is empty
int athlete::empty(void) const
{
	if(!name) return 1;

	return 0;
}





