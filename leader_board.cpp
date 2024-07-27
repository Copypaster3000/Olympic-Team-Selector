//leader_board.cpp
//Drake Wheeler
//CS302
//Karla Fant
//Program 2
//7/16/2024

#include "leader_board.h"
#include <iostream>
#include <string>
using namespace std;



//constructor
leader_board::leader_board() : skaters(), sprinters(), archers()
{}



//destructor
leader_board::~leader_board()
{}



//introduction to user
void leader_board::intro(void)
{
	cout << "\nThis program will help you select your dream team for the upcoming Olympics. You are putting" << endl;
	cout << "together your dream team for three different sports, skating, 100-meter sprint, and archery. You" << endl;
	cout << "can add an athlete to any sport. When you do you will enter the details about the athlete" << endl;
	cout << "including their medals won this season and their performance at the Olympic trials. This" << endl;
	cout << "program will rank them based on their stats. The better the stats the higher the ranking and if" << endl;
	cout << "the athlete has won any medals that season it will also boost their ranking. You can add or" << endl;
	cout << "remove an athlete from any of the sports at any time. You can view the ranking list of each type" << endl;
	cout << "of athlete and when you are done you can choose to end the program." << endl;

	return;
}



//returns menu choice from user
int leader_board::menu(void)
{
	int choice {};

	cout << "\nMenu:" << endl;
	cout << "1) Add a new athlete" << endl;
	cout << "2) Remove an athlete" << endl;
	cout << "3) View the ranking list of the athlete for a particular sport" << endl;
	cout << "4) End program" << endl;
	cout << "Enter choice as an integer: ";
	cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3 && choice != 4) //While user input is invalid
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Ivalid input. Enter choice from the menu as an integer: ";
		cin >> choice;
	}
	
	return choice; //Return user's choice as an int
}



//returns sub_menu 1 choice from user
int leader_board::sub_menu1(void)
{
	int choice {}; //holds user input

	cout << "\nWhat sport would you like to add an athlete to?" << endl;
	cout << "1) Skaters" << endl;
	cout << "2) Sprinters" << endl;
	cout << "3) Archer" << endl;
	cout << "Enter choice as an integer: ";
	cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3) //While user input is invalid
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Ivalid input. Enter choice from the menu as an integer: ";
		cin >> choice;
	}

	return choice;
}



//Adds athlete type based on int passed in
void leader_board::add_athlete(int sport)
{
	try
	{
		if(sport == 1) //If the user want to add a skater
		{
			skater new_skater; //create new skater object
			new_skater.input_info(); //Enter skater stats from user

			//Adds new skater to skaters DLL
			if(!skaters.add_athlete(new_skater)) cout << "\nError adding skater to DLL." << endl; //Displays error if issue
		}
		else if(sport == 2) //If user wants to add a sprinter
		{
			sprinter new_sprinter; //create new sprinter object
			new_sprinter.input_info(); //Input sprinter stats from user

			//Adds new sprinter to sprinters DLL
			if(!sprinters.add_athlete(new_sprinter)) cout << "\nError adding skater to DLL." << endl; //Displays error if issue
		}
		else //user wants to add new archer
		{
			archer new_archer; //create new archer object
			new_archer.input_info(); //Input archer stats from user

			//Adds new archer to archers DLL
			if(!archers.add_athlete(new_archer)) cout << "\nError adding archer to DLL." << endl; //Displays error if issue
		}
	}
	catch (over_write error) //catch error from inputing new athlete info
	{
		cout << error.detail << endl;
	}
	//catch error from adding new athlete into dll in sorted position and there was missing data to do so
	catch (missing_score error)
	{
		cout << error.detail << endl;
	}

	return;
}



//returns sub_menu 2 choice from user
int leader_board::sub_menu2(void)
{
	int choice {}; //holds user input

	cout << "\nWhat sport would you like to remove an athlete from?" << endl;
	cout << "1) Skaters" << endl;
	cout << "2) Sprinters" << endl;
	cout << "3) Archer" << endl;
	cout << "Enter choice as an integer: ";
	cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3) //While user input is invalid
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Ivalid input. Enter choice from the menu as an integer: ";
		cin >> choice;
	}

	return choice;
}



//Remove's athlete of user's choice
void leader_board::remove_athlete(int sport)
{
	string athlete_name; //Stores name of athlete to remove

	cout << "\nEnter the name of the athlete you would like to remove. It is case sensative." << endl;
	cout << "Enter: ";
	//clear input stream
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin, athlete_name); //Gets athlete name from users

	try
	{
		if(sport == 1) //If user chose to remove a skater
		{
			//attempt to remove athlete from list
			if(!skaters.remove_athlete(athlete_name)) cout << "\nThere is no skater named \"" << athlete_name << "\" in the list." << endl;
			else cout << "\n" << athlete_name << " was removed from the list." << endl;
		}
		else if(sport == 2) //If user chose to remove a sprinter
		{
			//attempt to remove athlete from list
			if(!sprinters.remove_athlete(athlete_name)) cout << "\nThere is no sprinter named \"" << athlete_name << "\" in the list." << endl;
			else cout << "\n" << athlete_name << " was removed from the list." << endl;
		}
		else //If user chose to remove an archer
		{
			//attempt to remove athlete from list
			if(!archers.remove_athlete(athlete_name)) cout << "\nThere is no archer name \"" << athlete_name << "\" in the lsit." << endl;
			else cout << "\n" << athlete_name << " was removed from the list." << endl;
		}
	}
	catch(no_data error) //Catches any error thrown by .remove_athlete()
	{
		cout << error.detail << endl; //Displays that there is missing data from athlete name
	}

	return;
}



//returns sub_menu 3 choice from user
int leader_board::sub_menu3(void)
{
	int choice {}; //holds user input

	cout << "\nWhat sports rank list would you like to see?" << endl;
	cout << "1) Skaters" << endl;
	cout << "2) Sprinters" << endl;
	cout << "3) Archer" << endl;
	cout << "Enter choice as an integer: ";
	cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3) //While user input is invalid
	{
		//Clear input stream
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Ivalid input. Enter choice from the menu as an integer: ";
		cin >> choice;
	}

	return choice;
}



//displays ranked list of the athletes of sport passed in
void leader_board::display_ranks(int sport)
{
	try
	{
		if(sport == 1) //If user chose to display skaters
		{
			//Diplay skater's list
			if(!skaters.display_list()) cout << "\nThere are no athletes logged in the skaters list." << endl;
		}
		else if(sport == 2) //If user chose to display sprinters
		{
			//Display sprinter's list
			if(!sprinters.display_list()) cout << "\nThere are sprinters logged in the sprinters list." << endl;
		}
		else //If user chose to display archers
		{
			//Display archers list
			if(!archers.display_list()) cout << "\nThere are no archers logged in the archers list." << endl;
		}
	}
	catch(no_data error) //Catches any error thrown by .display_list
	{
		cout << error.detail << endl; //Displays that there is missing data from athlete name
	}

	return;
}

