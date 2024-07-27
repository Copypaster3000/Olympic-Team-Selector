//node.h
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024


#ifndef NODE_H
#define NODE_H

template<typename TYPE>
class node
{
	public:
		node();
		~node();
		node<TYPE>* & get_next(void); //Returns node's next pointer
		node<TYPE>* & get_prev(void); //Returns node's prev pointer
		
		TYPE get_athlete(void) const; //Returns data object
		void set_athlete(const TYPE & to_set); //Sets data with athlete TYPE object passed in, throws overwrite error if athlete already has data
			
	protected:
		TYPE athlete;

		node<TYPE>* next;
		node<TYPE>* prev;
};

#include "node.tpp"

#endif // NODE_H
