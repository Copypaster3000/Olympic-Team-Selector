//archer.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#include "archer.h"


//constructor
archer::archer() : match1_score(-1), match2_score(-1), match3_score(-1)
{}



//destructor
archer::~archer()
{}



//used to ouput all the archer's info
ostream & operator << (ostream & out, const archer & op2)
{
	//If match1 score not yet entered
	if(op2.match1_score == -1 || op2.match2_score == -1 || op2.match3_score == -1)
	{
		no_data error;
		throw error;
	}

	//Displays base classes data members then archer's data members
	out << static_cast<const athlete &> (op2) << "   Match one score: " << op2.match1_score << "   Match two score: " << op2.match2_score << "   Match three score: " << op2.match3_score;

	return out;
}



//equality operator
bool operator == (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() == op2.calc_rank_score()) return true;

	return false;
}



//inequality operator
bool operator != (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() != op2.calc_rank_score()) return true;

	return false;
}



//greater than or equal to operator
bool operator >= (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() >= op2.calc_rank_score()) return true;

	return false;
}



//greater than operator
bool operator > (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() > op2.calc_rank_score()) return true;

	return false;
}



//less than or equal to operator
bool operator <= (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() <= op2.calc_rank_score()) return true;

	return false;
}



//less than operator
bool operator < (const archer & op1, const archer & op2)
{
	//compares rank scores of archers
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() < op1.calc_rank_score()) return true;

	return false;
}



//returns archer's rank score by adding all of their match scores together plus their points from medals
int archer::calc_rank_score(void) const
{
	return match1_score + match2_score + match3_score + calc_medals_score(2);
}



//set archer info with user input
void archer::input_info(void)
{
	//if any match scores are already set
	if(match1_score != -1 || match2_score != -1 || match3_score != -1)
	{
		over_write error;
		throw error;
	}

	input_athlete_stats("Archer");

	cout << "\nEnter the archer's three match scores out of 100." << endl;
	cout << "Match one score: ";
	cin >> match1_score;
	cout << "Match two score: ";
	cin >> match2_score;
	cout << "Match three score: ";
	cin >> match3_score;

	return;
}




	


