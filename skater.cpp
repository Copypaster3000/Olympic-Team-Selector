//skater.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This file holds the function definitions for the skater class. These classes define overloaded operators, use base class
//functions, edit class data member functions and parse through data members, to edit skater stats, display them, and compare them.

#include "skater.h"
using namespace std;



//default constructor
skater::skater() : athlete(), best_trick(nullptr)
{

}



//destructor
skater::~skater()
{
	delete[] best_trick; //deallocate memory
	best_trick = nullptr;
}



//copy constructor
skater::skater(const skater & og_skater) : athlete(og_skater)
{
	best_trick = new char[strlen(og_skater.best_trick)]; //allocates correct space
	strcpy(best_trick, og_skater.best_trick); //copies string

	run_scores = og_skater.run_scores; //copies run scores vector
	trick_scores = og_skater.trick_scores; //copies tirck scores vector
}



//assingment operator
skater & skater::operator = (const skater & og_skater)
{
	if(this == &og_skater) return *this; //check for  self assignment

	athlete::operator=(og_skater); //base class assignment operator

	if(best_trick) delete[] best_trick; //if there's a best_trick delete it

	best_trick = new char[strlen(og_skater.best_trick) + 1]; //allocates correct memory for best_trick
	strcpy(best_trick, og_skater.best_trick); //set correct best trip

	run_scores = og_skater.run_scores; //sets run_scores vector
	trick_scores = og_skater.trick_scores; //sets trick_scores vector
										   
	return *this; //Returns object to be assigned
}



//ostream operator, ouputs all skater info 
ostream & operator << (ostream & out, const skater & op2)
{
	//if there is no data in a variable that is accessed
	if(!op2.best_trick || op2.run_scores.empty() || op2.trick_scores.empty())
	{
		no_data error;
		throw error;
	}

	out << static_cast<const athlete &> (op2) << "   Best trick: " << op2.best_trick << "   Run scores: ";

	for (auto it = op2.run_scores.begin(); it != op2.run_scores.end(); ++it) //Iterate through each score in run scores
	{
		if(it != op2.run_scores.begin()) out << ", "; //Seperates the scores by commas w/o puting a comma before the 1st score

		out << *it; //Displays score at current element
	}

	out << "   Trick scores: ";

	for (auto it = op2.trick_scores.begin(); it != op2.trick_scores.end(); ++it) //Iterate through each score in trick scores
	{
		if(it != op2.trick_scores.begin()) out << ", "; //Seperates the scores by commas w/o puting a comma before the 1st score
														//
		out << *it; //Displays score at current element
	}

	return out;
}



//greater than or equal to operator
bool operator >= (const skater & op1, const skater & op2)
{
	//compares rank scores of skaters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() >= op2.calc_rank_score()) return true;

	return false;
}



//greater than operator
bool operator > (const skater & op1, const skater & op2)
{
	//compares rank scores of skaters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() > op2.calc_rank_score()) return true;

	return false;
}



//less than or equal to operator
bool operator <= (const skater & op1, const skater & op2)
{
	//compares rank scores of skaters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() <= op2.calc_rank_score()) return true;

	return false;
}



//less than operator
bool operator < (const skater & op1, const skater & op2)
{
	//compares rank scores of skaters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() < op2.calc_rank_score()) return true;

	return false;
}



//calculates skater rank score by summing top 4 scores from run scores and trick score and adds that to score from medals and returns it
float skater::calc_rank_score(void) const
{
	if(run_scores.empty() || trick_scores.empty())
	{
		missing_score error;
		throw error;
	}
	
	int total_score = 0; //Holds accumlative score from the 4 hightest run and trick scores
	array<float, 4> highest_scores = {0, 0, 0, 0}; //Will hold the four highest scores

	for(vector<float>::const_iterator it = run_scores.begin(); it != run_scores.end(); ++it) //Iterates through each element in run_scores
	{
		for(int i = 0; i < 4; ++i) //Iterates through each element in array of highest_scores
		{
			if(*it < highest_scores[i]) //If element from run_scores is greater than element from highest scores
			{
				highest_scores[i] = *it; //Set highest score element to run score element
				break; //Break out of inner loop so it doesn't replace anymore element with the same run score
			}
		}
	}

	for (vector<float>::const_iterator it = trick_scores.begin(); it != trick_scores.end(); ++it) //Iterate through each element in trick_score
	{
		for(int i = 0; i < 4; ++i) //Loops for each element in highest_scores
		{
			if(*it > highest_scores[i]) //If trick score is higher then element in higher scores
			{
				highest_scores[i] = *it; //Replace highest score element with current trick score
				break; //break out of inner loop so that it doesn't rellpace anymore high score elements with the same trick score
			}
		}
	}

	for(int i = 0; i < 4; ++i) //loops for each element in highest_score
	{
		total_score += highest_scores[i];
	}

	//Return total score from skater olympic trials plus score from skater's medals won this season with a weight of 0.5 to match the scale of run and trick scores
	return total_score + calc_medals_score(0.5);
}
				


//Sets skater data with user input
void skater::input_info(void)
{
	int score = 0; //Holds current score for run or trick
	int entering = 0; //answer for whether user wants to enter another score
	string trick; //Temporarily hold's best trick

	if(best_trick) //If there is already a trick stored
	{
		delete[] best_trick;
		over_write error;
		throw error;
	}

	input_athlete_stats("Skater");

	cout << "\nEnter the skater's two run scores out of 10 during the trials." << endl;
	cout << "Enter run one's score as an integer: ";
	cin >> score;
	run_scores.push_back(score);
	cout << "Enter run two's score as an intger: ";
	cin >> score;
	run_scores.push_back(score);

	cout << "\nEnter a score out of 10 for each trick the skater performed in the runs." << endl;
	cout << "Enter trick score: ";
	cin >> score;
	trick_scores.push_back(score);

	cout << "\nWould you like to enter another trick score?";
	entering = yes_or_no();

	while(entering)
	{
		cout << "\nEnter the trick score out of 10 as an integer: ";
		cin >> score;
		trick_scores.push_back(score);
		cout << "\nWould you like to enter another trick score?";
		entering = yes_or_no();
	}


	cout << "\nEnter the name of the skater's best trick: ";
	//Clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin, trick); //Get trick from user

	best_trick = new char[trick.size() + 1]; //Allocate memory
	strcpy(best_trick, trick.c_str()); //set with string

	return;
}


	




	

