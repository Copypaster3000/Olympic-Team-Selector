//athlete.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This is the header file for the athlete class. This class is a parent class to each of the specific athlete types. This class manages the athlete name,
//sport, and medals list. The overloaded operators allow clients to compare the athlete name with strings, output athlete details, and add medals to the
//medals list.

#ifndef ATHLETE_H
#define ATHLETE_H

#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include "error.h"


class athlete
{
	public:
		athlete(); //default constructor
		~athlete(); //destructor

		athlete(const athlete & obj); //copy constructor				  
		athlete & operator = (const athlete & obj); //assignment operator, sets this object with deep copy of object set to				
													//
		//The equality operator will be used to compare if a string is equivalent to an athlete's name or not
		//Throws no_data error if the athlete does not have a name
        friend bool operator == (const athlete &, const string &);
        friend bool operator == (const string &, const athlete &);
        friend bool operator != (const athlete &, const string &);
        friend bool operator != (const string &, const athlete &);
												  
		//addition assignment opperator, add's medal placement to athlete's medals list
		athlete & operator += (int medal_placement); //throws bad data error if user inputs medal that is not 1, 2, or 3
		friend athlete operator + (const athlete & obj, int medal_placement); //addition opperator, this function will be used to add a medal to the skater's list of
		friend athlete operator + (int medal_placement, const athlete & obj); //medals, would be used like skater_obj = skater_obj + medal_placement; throws same error as += operator

		friend istream & operator >> (istream & in, athlete & op2); //Used to input the athlete's name, throws over_write error if athlete already has a name
		friend ostream & operator << (ostream & out, const athlete & op2); //Used to output all of the athletes info, throws no data error if name or sport is null/empty
																	   
		float calc_medals_score(float weight) const; //Returns the ranking score for the athlete's medals, pass in the weighting for the medals based on athlete's sport
		void input_athlete_stats(string sp); //Gets user input to set name and medals, pass in sport type, throws over write error if any data is overwritten
											 
		int yes_or_no(void) const; //Gets a yes or no answer from the user, returns 1 for yes, 0 for no
		int medal_from_user(void) const; //Gets medal placement from user, returns 1 for gold, etc..
		int empty(void) const; //Returns 1 if name null, 0 if not

	protected:
		char* name; //athlete's name
		string sport; //athlete's sport
		list<int> medals; //list of medals won at competitions this year, each element has an int for the medal they won, 1 for gold, etc..

};


#endif // ATHLETE_H
