//leader_board.h
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024
//This is the header file for the leader_board class. This class allows the client to explain the program to the user, display the menu options
//and get the users menu choice and then perform the user choice. The choices include adding an athlete, removing and athlete, and displaying a list
//of the ranked athletes for a certain sport.

#ifndef LEADER_BOARD_H
#define LEADER_BOARD_H

#include "dll.h"
#include "sprinter.h"
#include "skater.h"
#include "archer.h"

class leader_board
{
	public:
		leader_board(); //Constructor
		~leader_board(); //destructor
		void intro(void); //Explains the program to the user
		int menu(void); //Returns user's menu selection
		int sub_menu1(void); //Returns user's menu selection for which team to add an athlete to
		int sub_menu2(void); //Returns user's menu selection for which team to remove an athlete from
		int sub_menu3(void); //Returns user's menu selection for which team ranking to view
		void add_athlete(int sport); //Adds new athlete, sport dependant on user input passed in
		void remove_athlete(int sport); //Remove's an athelete base on user's input
		void display_ranks(int sport); //Displays ranked list of the sport passed in



	private:
		//Lists of athletes from each sport in sorted order best to worst
		dll<skater> skaters; 
		dll<sprinter> sprinters;
		dll<archer> archers;
};


#endif // LEADER_BOARD_H

