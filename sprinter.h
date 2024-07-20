//sprinter.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#ifndef SPRINTER_H
#define SPRINTER_H

#include "athlete.h"


class sprinter : public athlete 
{
	public:
		sprinter(); //default constructor
		~sprinter(); //destructor
					 
		sprinter(const sprinter & obj); //copy constructor
		sprinter & operator = (const sprinter & obj); //assignment operator

		friend ostream & operator << (ostream & out, const sprinter & op2); //Used to output all of sprinter info

		//All of the relational and equality operators will
        //be used to compare the rank scores of athlets
        friend bool operator == (const sprinter &, const sprinter &);
        friend bool operator != (const sprinter &, const sprinter &);
        friend bool operator >= (const sprinter &, const sprinter &);
        friend bool operator > (const sprinter &, const sprinter &);
        friend bool operator <= (const sprinter &, const sprinter &);
        friend bool operator < (const sprinter &, const sprinter &);		

		int calc_rank_score(void); //calculates and returns sprinter's score based on stats, which is used for ranking
		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten

	private:
		int fastest_time; //Fastest 100_m sprint time recorded
		int average_time; //average 100_m sprint time over this season
						  //Note: sprinters are ranked based on their fastest time and average time being added together



};


#endif // SPRINTER_H

