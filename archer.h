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
				   
		archer(const archer & obj); //copy constructor					
		archer & operator = (const archer & obj); //assignment operator

		friend ostream & operator << (ostream & out, const archer & op2); //Used to output all of the archer's info

		//All of the relational and equality operators will
        //be used to compare the rank scores of archers
        friend bool operator == (const archer &, const archer &);
        friend bool operator != (const archer &, const archer &);
        friend bool operator >= (const archer &, const archer &);
        friend bool operator > (const archer &, const archer &);
        friend bool operator <= (const archer &, const archer &);
        friend bool operator < (const archer &, const archer &);		

		int calc_rank_score(void); //calculates and returns archer's score based on stats which is used for ranking
		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten



	private:
		int match1_score; //Match score out of 100
		int match2_score; //score out of 100
		int match3_score; //score out of 100
						//Note: The archers cumulative score is used for ranking


};


#endif // ARCHER_H
