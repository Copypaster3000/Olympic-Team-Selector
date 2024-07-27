//node.tpp
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024

#ifndef NODE_TPP
#define NODE_TPP

#include "error.h"
#include <iostream>

//constructor
template <typename TYPE>
node<TYPE>::node() : next(nullptr), prev(nullptr)
{}



//destructor
template <typename TYPE>
node<TYPE>::~node()
{
}



//Returns head
template <typename TYPE>
node<TYPE>* & node<TYPE>::get_next(void)
{
	return next;
}



//Returns prev
template <typename TYPE>
node<TYPE>* & node<TYPE>::get_prev(void)
{
	return prev;
}



//Returns athlete object
template <typename TYPE>
TYPE node<TYPE>::get_athlete() const
{
	return athlete;
}



//Sets node's athlete member with object passed in
template <typename TYPE>
void node<TYPE>::set_athlete(const TYPE & to_set)
{
	if(!athlete.empty()) //If athlete of node already has a name
	{
		over_write error;
		throw error; //Throw over write error
	}

	athlete = to_set; //Assigns node's athlete data member with obj passed in info
}


#endif // NODE_TPP
