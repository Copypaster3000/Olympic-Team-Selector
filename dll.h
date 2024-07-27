//dll.h
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024


#ifndef DLL_H
#define DLL_H


#include "node.h"
#include <string>
using std::string;

template <typename TYPE>
class dll
{
	public:
		dll();
		~dll();
		int add_athlete(const TYPE & to_add); //Adds athlete in sorted position to dll, returns 1 for success, throws over_write error if athlete already has name
		int remove_athlete(const string & nm); //Removes althete if a matching name is found, returns 1 for success, 0 for no match, throws no data error if althelet is missing name
		int display_list(void) const; //Displays each ranked athlete in order, returns 1 for success 0 if no athletes in list, throws no data error is athlete is missing name
		

	private:
		node<TYPE>* head; //Points to head of dll
		node<TYPE>* tail; //points to tail of dll

		int add_athlete(node<TYPE>* & head, const TYPE & to_add); //Recursive part of adding athlete in sorted position to dll
		int remove_athlete(const string & nm, node<TYPE>* & head); //Recursive part of removing athlete
		int display_list(node<TYPE>* head, int rank) const; //Recusrive part of display all


};



#include "dll.tpp"
#endif // DLL_H
