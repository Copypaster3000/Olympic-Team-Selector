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
		//used to output all sprinter info, throws no data error if data members have no bet set yet
		friend ostream & operator << (ostream & out, const sprinter & op2); 

		//All of the relational and equality operators will
        //be used to compare the rank scores of athlets
		//Throws missing score error if a score used to calc the rank score has not been entered
        friend bool operator == (const sprinter &, const sprinter &);
        friend bool operator != (const sprinter &, const sprinter &);
        friend bool operator >= (const sprinter &, const sprinter &);
        friend bool operator > (const sprinter &, const sprinter &);
        friend bool operator <= (const sprinter &, const sprinter &);
        friend bool operator < (const sprinter &, const sprinter &);		

		float calc_rank_score(void) const; //calculates and returns sprinter's score based on stats, which is used for ranking
		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten

	private:
		float fastest_time; //Fastest 100_m sprint time recorded
		float average_time; //average 100_m sprint time over this season
						  //Note: sprinters are ranked based on their fastest time and average time being added together



};


#endif // SPRINTER_H

