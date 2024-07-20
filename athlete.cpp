//athlete.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#include "athlete.h"


//default constructor
athlete::athlete() : name(nullptr), sport("")
{

}



//destructor
athlete::~athlete()
{
	delete[] name; //deallocates memory
}



//copy constructor
athlete::athlete(const athlete & obj) : sport(obj.sport), medals(obj.medals)
{
	name = new char[strlen(obj.name) + 1]; //allocates correct memory
	strcpy(name, obj.name); //copies name
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



//addition assignment operator
athlete & athlete::operator += (int medal)
{
	medals.push_back(medal); //Adds medal to back of list of medals

	return *this;
}



//addition operator (friend)
athlete operator + (const athlete & op1, int medal)
{
	athlete temp = op1; //Create temp athlete object and set it to athlete obj passed in

	temp += medal; //Add medal to athlete's list of medals using previously overloaded += operand

	return temp;
}



//addition operator (friend)
athlete operator + (int medal, const athlete & op2)
{
	athlete temp = op2; //Create temp athlete object and set it to athlete obj passed in

	temp += medal; //Add medal to athlete's list of medals using previously overloaded += operand

	return temp;
}



// >> operator
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
	out << "Athlete: " << op2.name << "\tSport: " << op2.sport << "\tThis seasons medals: ";

	for (auto it = op2.medals.begin(); it != op2.medals.end(); ++it) //Iterate through each medal in medals list
	{
		if(it != op2.medals.begin()) out << ", "; //Seperates the medals by commas w/o puting a comma before the 1st medal

		out << *it; //Displays medal at current element
	}


	return out; //Returns ostream operand
}



//equality operator, checks if the athlete's rank scores are the same


//Returns medals ranking score
float athlete::calc_medals_score(float weight)
{
	float score = 0; //holds score to be returned

	for(const int & medal : medals) //Loops through each medal in medals
	{
		//Adds points to score, more points for higher placement
		if(medal == 1) score += 3 * weight;
		else if(medal == 2) score += 2 * weight;
		else if (medal == 3) score += 1 * weight;
	}

	return score; //returns score
}











