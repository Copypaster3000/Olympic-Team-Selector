//athlete.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#ifndef ATHLETE_H
#define ATHLETE_H

#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include "error.h"

using namespace std;

class athlete
{
	public:
		athlete(); //default constructor
		~athlete(); //destructor

		athlete(const athlete & obj); //copy constructor				  
		athlete & operator = (const athlete & obj); //assignment operator, sets this object with deep copy of object set to				
												  
		athlete & operator += (int medal_placement); //addition assignment opperator, add's medal placement to athlete's medals list
		friend athlete operator + (const athlete & obj, int medal_placement); //addition opperator, this function will be used to add a medal to the skater's list of
		friend athlete operator + (int medal_placement, const athlete & obj); //medals, would be used like skater_obj = skater_obj + medal_placement;

		friend istream & operator >> (istream & in, athlete & op2); //Used to input the athlete's name
		friend ostream & operator << (ostream & out, const athlete & op2); //Used to output all of the athletes info

		//All of the relational and equality operator will be 
		//used to compare the rank scores of athletes
		/* THINKING I WOULD NOT DEFINE THESE HERE BECAUSE THE RANK SCORE WHICH IS BEING COMPARED IS DEPENDANT ON THE 
		 * MEDAL WEIGHT WHICH IS DEPENDANT ON THE ATHLETE TYPE, SO IT WILL BE PASSED IN TO CALC MEDAL SCORE WHICH WILL
		 * BE CALLED IN EACH ATHLETE TYPE'S EQUALITY AND RELATIONAL OVERLOADED OPERTOR DEFINITIONS
        friend bool operator == (const athlete &, const athlete &);
        friend bool operator != (const athlete &, const athlete &);
        friend bool operator >= (const athlete &, const athlete &);
        friend bool operator > (const athlete &, const athlete &);
        friend bool operator <= (const athlete &, const athlete &);
        friend bool operator < (const athlete &, const athlete &);		
		*/
																	   
		int input_athlete_stats(void); //Gets user input to set name, sports, and medals
		float calc_medals_score(float weight); //Returns the ranking score for the athlete's medals, pass in the weighting for the medals based on athlete's sport


	protected:
		char* name; //athlete's name
		string sport; //athlete's sport
		list<int> medals; //list of medals won at competitions this year, each element has an int for the medal they won, 1 for gold, etc..

};


#endif // ATHLETE_H
