#include "include.h"
using namespace std;

void Menu::choiceMenu(){

	Menu menu;
	int i = menu.firstMenu();
	if (i == 1){
		menu.fridgeMenu();
	}
	if (i == 2){
		menu.cookBookMenu();
	}
}
int Menu::firstMenu(){
	cout << "--------------------------------------------" << endl;
	cout << "|                WHAT TO COOK              |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|          PRESS 1 FOR THE FRIDGE          |" << endl;
	cout << "|          PRESS 2 FOR THE COOKBOOK        |" << endl;
	cout << "|          PRESS 3 TO QUIT                 |" << endl;
	cout << "--------------------------------------------" << endl;

	do {
		repeat_menu = false;
		cin >> value_menu;
		switch (value_menu) {
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		default:
			/*This part is used to loop on the menu in case of wrong input */
			repeat_menu = true;
			cin.clear();
			cin.ignore(1000, '\n');
			return 4;
			cout << "Error, input not recognized" << endl;
			break;
		}
	} while (repeat_menu);
}
void Menu::fridgeMenu(){

	value_menu = 0; //reset the value of the menu number

	cout << "--------------------------------------------" << endl;
	cout << "|                The Fridge                |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|          PRESS 1 TO ADD AN INGREDIENT    |" << endl;
	cout << "|          PRESS 2 TO REMOVE AN INGREDIENT |" << endl;
	cout << "|          PRESS 3 TO LIST THE INGREDIENTS |" << endl;
	cout << "|          PRESS 4 TO SEARCH A RECEIPE     |" << endl;
	cout << "|          PRESS 5 TO QUIT                 |" << endl;
	cout << "--------------------------------------------" << endl;
	do {
		string name;
		int quantity = 0;
		string quantityType;
		repeat_menu = false;
		cin >> value_menu;
		switch (value_menu) {
		case 1:
			cout << "--------------------------------------------" << endl;
			cout << "Name?" << endl;
			cin.sync(); // allow to use space in cin
			getline(cin, name);
			cout << "Quantity?" << endl;
			cin.sync();
			cin >> quantity;
			cout << "Type of quantity? (grams, liters, etc...)" << endl;
			cin.sync();
			getline(cin, quantityType);

			if (Fridge::AddIngredient(name, quantity, quantityType)){
				cout << "--------------------------------------------" << endl;
				cout << "Ingredient added" << endl;
				fridgeMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "Error to add ingredient" << endl;
				fridgeMenu();
				break;
			}
		case 2:
			Fridge::ListIngredient();
			cout << "--------------------------------------------" << endl;
			cout << "Name?" << endl;
			cin.sync();
			getline(cin, name);
			
			if (Fridge::RemoveIngredient(name)){
				cout << "--------------------------------------------" << endl;
				cout << "Ingredient removed" << endl;
				fridgeMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "Error to remove ingredient, does it exist?" << endl;
				fridgeMenu();
				break;
			}
		case 3:
			if (Fridge::ListIngredient()){
				fridgeMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "Error to list ingredient" << endl;
				fridgeMenu();
				break;
			}
		case 4:
			if (Fridge::SearchReceipe()){
				fridgeMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "No receipe available" << endl;
				fridgeMenu();
				break;
			}
			break;
		case 5:
			choiceMenu();
			break;
		default:
			/*This part is used to loop on the menu in case of wrong input */
			repeat_menu = true;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error, input not recognized" << endl;
			break;
		}
	} while (repeat_menu);
}
void Menu::cookBookMenu(){

	value_menu = 0; //reset the value of the menu number

	cout << "--------------------------------------------" << endl;
	cout << "|                The Cook Book             |" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "|          PRESS 1 TO ADD A RECEIPE        |" << endl;
	cout << "|          PRESS 2 TO REMOVE A RECEIPE     |" << endl;
	cout << "|          PRESS 3 TO LIST RECEIPE         |" << endl;
	cout << "|          PRESS 4 TO QUIT                 |" << endl;
	cout << "--------------------------------------------" << endl;
	do {
		string name,difficulty,time,stop;
		string ingredientName, typeQuantity;
		int quantity;
		const int counterIngredient = 50; // maximum of Ingredients in a receipe
		int nbIngredient = 0;
		Ingredient* ingredients = new Ingredient[counterIngredient];
		repeat_menu = false;
		cin >> value_menu;
		switch (value_menu) {
		case 1:
			cout << "--------------------------------------------" << endl;
			cout << "Name?" << endl;
			cin.sync();
			getline(cin, name);
			cout << "Difficulty?" << endl;
			cin.sync();
			getline(cin, difficulty);
			cout << "Time?" << endl;
			cin.sync();
			getline(cin, time);
			cout << "--------------------------------------------" << endl;
			do
			{
				cout << "--------------------------------------------" << endl;
				cout << "Ingredient " << endl;
				cout << "Name?" << endl;
				cin.sync();
				getline(cin, ingredientName);
				cout << "Quantity?" << endl;
				cin.sync();
				cin >> quantity;
				cout << "Type of quantity? (grams, liters, etc...)" << endl;
				cin.sync();
				getline(cin, typeQuantity);
				cout << "Press \"QUIT\" to finish your receipe or OK to continue"<< endl;
				cin.sync();
				getline(cin, stop);
				//ingredients[nbIngredient] = new Ingredient(ingredientName, quantity, typeQuantity);
				ingredients[nbIngredient] = Ingredient(ingredientName, quantity, typeQuantity);
				nbIngredient++;
			} while (stop != "QUIT");
			try{
				if (CookBook::AddReceipe(name, difficulty, time, ingredients)){
					cout << "--------------------------------------------" << endl;
					cout << "receipe added" << endl;
					cookBookMenu();
					break;
				}
				else{
					cout << "--------------------------------------------" << endl;
					cout << "Error to add receipe" << endl;
					
					cookBookMenu();
					break;
				}
				throw new string("AddReceipe");

			}
			catch (const string * e){
				cerr << "error with function" << *e << endl;
			}
		case 2:
			CookBook::ListReceipe();
			cout << "--------------------------------------------" << endl;
			cout << "Name?" << endl;
			cin >> name;

			if (CookBook::RemoveReceipe(name)){
				cout << "--------------------------------------------" << endl;
				cout << "receipe removed" << endl;
				cookBookMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "Error to remove receipe, does it exist?" << endl;
				cookBookMenu();
				break;
			}
		case 3:
			if (CookBook::ListReceipe()){
				cookBookMenu();
				break;
			}
			else{
				cout << "--------------------------------------------" << endl;
				cout << "Error to list receipes" << endl;
				cookBookMenu();
				break;
			}
		case 4:
			choiceMenu();
			break;
		default:
			/*This part is used to loop on the menu in case of wrong input */
			repeat_menu = true;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error, input not recognized" << endl;
			break;
		}
	} while (repeat_menu);
}