#ifndef MENU_FILE
#define MENU_FILE

#include "include.h"
/*This class provide the first menu for the user */
class Menu
{
private :
	int value_menu; //value of the input
	bool repeat_menu; //this attribute is true if the user write a wrong input
public:
	Menu(){} //constructor
	void choiceMenu();
	int firstMenu(); 
	void fridgeMenu();
	void cookBookMenu();
};

#endif MENU_FILE