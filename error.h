//error.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/18/2024
//This file holds the structs which will be thrown as errors

#include <iostream>
using namespace std;


struct over_write
{
	string detail = "A char* or string was over written.";
};


struct no_data
{
	string detail = "There is no data in a variable that was accessed.";
};


struct missing_score
{
	string detail = "When calulating the rank score for an athlete there were no entries in a variable that should have scores.";
};


struct bad_input
{
	string detail = "Bad input was gotten from the user.";
};

