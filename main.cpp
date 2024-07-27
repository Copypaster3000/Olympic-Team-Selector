//main.cpp
//Drake Wheeler
//CS302
//Program 2
//Karla Fant
//7/18/2024

#include "leader_board.h"

int main()
{
	int menu_choice {}; //Holds user's menu selection
	leader_board app; //Leader_board object to run application

	app.intro(); //Explains program to user

	while(menu_choice != 4) //While user has not selected to end program
	{
		menu_choice = app.menu(); //Get main menu choice from 

		if(menu_choice == 1)
		{
			menu_choice = app.sub_menu1(); //Sets menu choice with what sport user want to add an athlete to

			app.add_athlete(menu_choice); //Adds athlete to correct sport based on int passed in
		}
		else if(menu_choice == 2)
		{
			menu_choice = app.sub_menu2(); //Sets menu choice to what sport the user wants to remove an athlete from
			app.remove_athlete(menu_choice); //Removes athlete named by use from list
		}
		else if(menu_choice == 3)
		{
			menu_choice = app.sub_menu3(); //Sets meny choice to waht sport the user wants to display
			app.display_ranks(menu_choice); //Displays ranked list of athletes of sport user chose
		}

	}


	return 0;
}

