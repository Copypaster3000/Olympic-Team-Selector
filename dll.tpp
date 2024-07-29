//dll.tpp
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024
//This file holds the class defintion for the dll template class. These functions user operator overloaders and pointers to 
//add, remove, and display athletes in the dll.

#ifndef DLL_TPP
#define DLL_TPP
#include <iostream>


//constructor
template <typename TYPE>
dll<TYPE>::dll() : head(nullptr), tail(nullptr)
{}




//destructor
template <typename TYPE>
dll<TYPE>::~dll()
{
	delete_list(head); //deallocate dll
}



//deletes dll
template <typename TYPE>
void dll<TYPE>::delete_list(node<TYPE>* & head)
{
	if(!head) return; //Stop after reaching end of dll

	delete_list(head->get_next()); //Traverse to end of dll

	delete head; //On "the way back" delete nodes
}



//Add athlete in sorted order to dll
template <typename TYPE>
int dll<TYPE>::add_athlete(const TYPE & to_add)
{
	if(!head) //If dll is empty
	{
		head = new node<TYPE>; //set head equal to new node
		tail = head; //Set tail to head
					 
		head->set_athlete(to_add); //Set new node with new athlete

		return 1;
	}
	else if(to_add >= head->get_athlete()) //If new athlete needs to be added to front of dll
	{
		node<TYPE>* temp = head; //Hold onto old head with temp
		node<TYPE>* new_node = new node<TYPE>; //Create new node

		head = new_node; //Set head with new node
		head->set_next(temp); //Set new head's next ptr to old head
		temp->set_prev(head); //Set old head's prev ptr to new head

		head->set_athlete(to_add); //Set new node with new athlete

		return 1;
	}

	return add_athlete(head, to_add);
}



//Recursive part of add athlete
template <typename TYPE>
int dll<TYPE>::add_athlete(node<TYPE>* & current, const TYPE & to_add)
{
	if(to_add >= current->get_athlete()) //If athlete being add has a higher or equal rank score as current athlete in dll
	{	
		node<TYPE>* new_node = new node<TYPE>; //create new node
		node<TYPE>* temp = current->get_prev(); //Set temp pointer to prev node									 

		new_node->set_next(current); //Set new node's next ptr to current
		new_node->set_prev(temp); //Set new node's prev ptr to temp
		temp->set_next(new_node); //Set previous node's next ptr to new node
		current->set_prev(new_node); //Set current node's prev ptr to new node

		new_node->set_athlete(to_add); //Set new node with new athlete's info

		return 1;
	}
	else if(!current->get_next()) //If at tail and node wasn't already added
	{
		tail = new node<TYPE>; //create new node

		tail->set_prev(current); //Set new tail's prev ptr to old tail
		current->set_next(tail); //Set old tail's next ptr to new tail

		tail->set_athlete(to_add); //Set new node with new athlete's info

		return 1;
	}

	return add_athlete(current->get_next(), to_add);
}



//Remove's athlete with matching name of string passed in
template <typename TYPE>
int dll<TYPE>::remove_athlete(const string & to_remove)
{
	if(!head) return 0; //No athletes to remove

	if(head == tail) //If there is one node in dll
	{
		//if there is one node in the list and it is not a match, return 0;
		if(head->get_athlete() != to_remove) return 0;

		//else if it is a match
		delete head; //remove it
		head = nullptr; //Set dll points to null
		tail = nullptr;

		return 1; //for succesful removal
	}

	//If the athlete to be removed is at head and there is more than one node
	if(to_remove == head->get_athlete())
	{
		node<TYPE>* temp = head; //hold onto head;
		head = head->get_next(); //Set head to new head
		head->set_prev(nullptr);
		delete temp; //delete old head;
					 
		return 1; //for succesful removal
	}

	//If tail is the athlete to remove and there is more than one node
	if(to_remove == tail->get_athlete())
	{
		node<TYPE>* temp = tail; //Hold onto old tail
		tail = tail->get_prev(); //Set tail to new tail
		tail->set_next(nullptr); //Set new tail's next ptr to null
		delete temp; //Deletes old tail
					 
		return 1; //athlete was removed
	}

	//None of the special cases were hit, call recursive removal function
	return remove_athlete(to_remove, head->get_next());
}



//recursive part of remove athlete
template <typename TYPE>
int dll<TYPE>::remove_athlete(const string & to_remove, node<TYPE>* & current)
{
	if(!current || current == tail) return 0; //No match found (tail already check in wrapper

	if(to_remove == current->get_athlete()) //If the current node is the athlete to remove
	{
		node<TYPE>* to_delete = current; //Hold onto current
		node<TYPE>* previous = current->get_prev(); //hold onto previous
		node<TYPE>* next = current->get_next(); //hold onto next
		previous->set_next(next); //Set previous nodes next ptr to node in front of to delete
		next->set_prev(previous); //Ser next nodes previous ptr to node behind to delete
		delete to_delete; //Delete removed athlete node

		return 1; //for succesful removal
	}

	//No match found call again to check next node
	return remove_athlete(to_remove, current->get_next());
}



//displays athlete in ranked order
template <typename TYPE>
int dll<TYPE>::display_list(void) const
{
	if(!head) return 0; //Return 0 if list is empty

	cout << endl; //New line for start of list

	//Call recursive funciton, pass in 1 for rank count
	return display_list(head, 1);
}



//recursive part of display_list
template <typename TYPE>
int dll<TYPE>::display_list(node<TYPE>* current, int rank) const
{
	if(!current) return 1; //End of list, return 1 for success

	if(current->get_athlete().empty())
	{
		no_data error;
		throw error;
	}

	//display athlete rank and details
	cout << rank << ") " << current->get_athlete() << endl;

	//Next recusrive call with rank incremented
	return display_list(current->get_next(), ++rank);
}



#endif //DLL_TPP
