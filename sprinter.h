//sprinter.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This is the header file for the sprinter class. The class represents a sprinter. It is derived from the athlete class. This class manages the sprinter's fastest time 
//and average time. The sprinter's info can be displayed, their rank score compared to other sprinters, and their stats can be input from the user. 

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

		//All of the relational are used to compare the rank scores of athlets
		//Throws missing score error if a score used to calc the rank score has not been entered
        friend bool operator >= (const sprinter &, const sprinter &);
        friend bool operator > (const sprinter &, const sprinter &);
        friend bool operator <= (const sprinter &, const sprinter &);
        friend bool operator < (const sprinter &, const sprinter &);		

		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten

	private:
		float fastest_time; //Fastest 100_m sprint time recorded
		float calc_rank_score(void) const; //calculates and returns sprinter's score based on stats, which is used for ranking
		float average_time; //average 100_m sprint time over this season
						  //Note: sprinters are ranked based on their fastest time and average time beingsubtracted from their medal score
						  //the fast their times the less is subtracted, this way they can still be ranked by who has the highest rank score



};


#endif // SPRINTER_H

