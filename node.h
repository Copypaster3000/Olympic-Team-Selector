//node.h
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024
//This is the header file for the node class. This is a template class and acts as a node in a doubly linked list. The TYPE object in this class is a 
//specific athlete object. This class gives accesss to the athlete object and allows clients to manage to pointers of the node.


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
		void set_next(node<TYPE>* ptr); //Sets node's next pointer
		void set_prev(node<TYPE>* ptr); //Sets node's prev pointer
		
		TYPE & get_athlete(void); //Returns data object
		void set_athlete(const TYPE & to_set); //Sets data with athlete TYPE object passed in, throws overwrite error if athlete already has data
			
	protected:
		TYPE athlete; //Holds object of a specific athlete

		node<TYPE>* next; //Points to next node in dll
		node<TYPE>* prev; //Points to preivous node in dll
};

#include "node.tpp"

#endif // NODE_H
