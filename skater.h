//skater.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024



#ifndef SKATER_H
#define SKATER_H

#include <vector>
#include <array>
#include "athlete.h"

class skater : public athlete
{
	public:
		skater(); //default constructor
		~skater(); //destructor

		skater(const skater & obj); //copy constructor
		skater & operator = (const skater & obj); //assignment operator

		//used to output all of the skater's info, throws no data error if there is no data in a variable that is accessed
		friend ostream & operator << (ostream & out, const skater & op2);

		//All of the relational operators will be used to compare the rank scores of skater
		//Throws missing score error is there is an error comparing rank scores
        friend bool operator >= (const skater &, const skater &);
        friend bool operator > (const skater &, const skater &);
        friend bool operator <= (const skater &, const skater &);
        friend bool operator < (const skater &, const skater &);		

		float calc_rank_score(void) const; //calculates and returns skater's score based on stats which is used for ranking
		void input_info(void); //Sets all skater's info from user input, throw error if any info is overwritten

	private:
		char* best_trick; //Holds the skaters most well known trick
		vector<float> run_scores; //Skater's overall run scores for 2 runs at the trials
		vector<float> trick_scores; //Skater's scores of each trick during their trials
									//Note: skaters are ranked based on their best 4 scores out of their runs and trick scores
};


#endif // SKATER_H
