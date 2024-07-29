//error.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/18/2024
//This is the header file for all the error structs. These structs are thrown as objects when an error is detected to be caught and learn about the issue. 

#ifndef ERROR_H
#define ERROR_H

#include <iostream>
using namespace std;


struct not_connected
{
	string detail = "A node is not properly connected in the dll.";
};

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

#endif // ERROR_H
