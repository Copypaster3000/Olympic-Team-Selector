//node.tpp
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024
//This file holds the funciton definitions for the node class. These functions use the node's members to change them or return
//them for client use. 

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



//sets node's next pointer with pointer passed in
template <typename TYPE>
void node<TYPE>::set_next(node<TYPE>* ptr)
{
	next = ptr;

	return;
}



//sets node's prev pointer with pointer passed in
template <typename TYPE>
void node<TYPE>::set_prev(node<TYPE>* ptr)
{
	prev = ptr;

	return;
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
TYPE & node<TYPE>::get_athlete()
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
