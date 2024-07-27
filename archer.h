//archer.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#include "athlete.h"

#ifndef ARCHER_H
#define ARCHER_H

class archer : public athlete
{
	public:
		archer(); //default constructor
		~archer(); //destructor

		//Displays all archer's info, throws no data error if members are missing data
		friend ostream & operator << (ostream & out, const archer & op2); 

		//All of the relational operators are used to compare the rank scores of archers
		//Throws missing score error if a score used to calc the rank score has not been entered
        friend bool operator >= (const archer &, const archer &);
        friend bool operator > (const archer &, const archer &);
        friend bool operator <= (const archer &, const archer &);
        friend bool operator < (const archer &, const archer &);		

		int calc_rank_score(void) const; //calculates and returns archer's score based on stats which is used for ranking
		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten



	private:
		int match1_score; //Match score out of 100
		int match2_score; //score out of 100
		int match3_score; //score out of 100
						//Note: The archers cumulative score is used for ranking


};


#endif // ARCHER_H
