//sprinter.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This file holds the function definitions for the sprinter class. These classes define overloaded operators, use base class
//functions, edit class data member functions and parse through data members, to edit skater stats, display them, and compare them.

#include "sprinter.h"
using namespace std;


//constructor
sprinter::sprinter() : fastest_time(-1), average_time(-1)
{}



//destructor
sprinter::~sprinter()
{}



// << opertor, output/displays
ostream & operator << (ostream & out, const sprinter & op2)
{
	if(op2.fastest_time == -1 || op2.average_time == -1)
	{
		no_data error;
		throw error;
	}

	out << static_cast<const athlete &> (op2) << "   Fastest 100m time: " << op2.fastest_time << "   Average 100m time: " << op2.average_time;

	return out;
}



//greater than or equal to operator
bool operator >= (const sprinter & op1, const sprinter & op2)
{
	//compares rank scores of sprinters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() >= op2.calc_rank_score()) return true;

	return false;
}



//greater than operator
bool operator > (const sprinter & op1, const sprinter & op2)
{
	//compares rank scores of sprinters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() > op2.calc_rank_score()) return true;

	return false;
}



//less than or equal to operator
bool operator <= (const sprinter & op1, const sprinter & op2)
{
	//compares rank scores of sprinters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() <= op2.calc_rank_score()) return true;

	return false;
}



//less than operator
bool operator < (const sprinter & op1, const sprinter & op2)
{
	//compares rank scores of sprinters
	//Throws missing score ERROR if there is an error with calc_rank_score
	if(op1.calc_rank_score() < op2.calc_rank_score()) return true;

	return false;
}



//returns sprinter's rank score
float sprinter::calc_rank_score(void) const
{
	if(fastest_time == -1 || average_time == -1) //If time hasn't been entered yet
	{
		missing_score error;
		throw error; //Throw error
	}

	//Returns the medal score minues the fastest time and the average time
	return calc_medals_score(0.025) - fastest_time - average_time;
}



//sets sprinter info with user input
void sprinter::input_info(void)
{
	if(fastest_time != -1 || average_time != -1) //If times already entered
	{
		over_write error;
		throw error;
	}

	input_athlete_stats("Sprinter"); //Set base athlete data member w/ user input, set sport as sprinter

	cout << "\nEnter the sprinter's fastest 100m time in seconds: ";
	cin >> fastest_time;
	//Clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the sprinter's average 100m time in seconds this season: ";
	cin >> average_time;

	return;
}



