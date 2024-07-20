//skater.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#include "skater.h"


//default constructor
skater::skater() : athlete(), best_trick(nullptr)
{

}



//destructor
skater::~skater()
{
	delete[] best_trick; //deallocate memory
}



//copy constructor
skater::skater(const skater & og_skater) : athlete(og_skater)
{
	best_trick = new char[strlen(og_skater.best_trick)]; //allocates correct space
	strcpy(best_trick, og_skater.best_trick); //copies string

	run_scores = og_skater.run_scores; //copies run scores vector
	trick_scores = og_skater.trick_scores; //copies tirck scores vector
}



//assingment operator
skater & skater::operator = (const skater & og_skater)
{
	if(this == &og_skater) return *this; //check for  self assignment

	athlete::operator=(og_skater); //base class assignment operator

	if(best_trick) delete[] best_trick; //if there's a best_trick delete it

	best_trick = new char[strlen(og_skater.best_trick) + 1]; //allocates correct memory for best_trick
	strcpy(best_trick, og_skater.best_trick); //set correct best trip

	run_scores = og_skater.run_scores; //sets run_scores vector
	trick_scores = og_skater.trick_scores; //sets trick_scores vector
										   
	return *this; //Returns object to be assigned
}



//ostream operator, ouputs all skater info 
ostream & operator << (ostream & out, const skater & op2)
{
	out << static_cast<const athlete &> (op2) << "\tBest trick: " << op2.best_trick << "\tRun scores: ";

	for (auto it = op2.run_scores.begin(); it != op2.run_scores.end(); ++it) //Iterate through each score in run scores
	{
		if(it != op2.run_scores.begin()) out << ", "; //Seperates the scores by commas w/o puting a comma before the 1st score

		out << *it; //Displays score at current element
	}

	out << "\tTrick scores: ";

	for (auto it = op2.trick_scores.begin(); it != op2.trick_scores.end(); ++it) //Iterate through each score in trick scores
	{
		if(it != op2.trick_scores.begin()) out << ", "; //Seperates the scores by commas w/o puting a comma before the 1st score

		out << *it; //Displays score at current element
	}

	return out;
}



//calculates skater rank score by summing top 4 scores from run scores and trick score and adds that to score from medals and returns it
int skater::calc_rank_score(void)
{
	int total_score = 0; //Holds accumlative score from the 4 hightest run and trick scores
	array<float, 4> highest_scores = {0, 0, 0, 0}; //Will hold the four highest scores

	for(vector<float>::iterator it = run_scores.begin(); it != run_scores.end(); ++it) //Iterates through each element in run_scores
	{
		for(int i = 0; i < 4; ++i) //Iterates through each element in array of highest_scores
		{
			if(*it < highest_scores[i]) //If element from run_scores is greater than element from highest scores
			{
				highest_scores[i] = *it; //Set highest score element to run score element
				break; //Break out of inner loop so it doesn't replace anymore element with the same run score
			}
		}
	}

	for (vector<float>::iterator it = trick_scores.begin(); it != trick_scores.end(); ++it) //Iterate through each element in trick_score
	{
		for(int i = 0; i < 4; ++i) //Loops for each element in highest_scores
		{
			if(*it > highest_scores[i]) //If trick score is higher then element in higher scores
			{
				highest_scores[i] = *it; //Replace highest score element with current trick score
				break; //break out of inner loop so that it doesn't rellpace anymore high score elements with the same trick score
			}
		}
	}

	for(int i = 0; i < 4; ++i) //loops for each element in highest_score
	{
		total_score += highest_scores[i];
	}

	//Return total score from skater olympic trials plus score from skater's medals won this season with a weight of 0.5 to match the scale of run and trick scores
	return total_score + calc_medals_score(0.5);
}
				


	

