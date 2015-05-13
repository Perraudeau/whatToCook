#ifndef FRIDGE_FILE
#define FRIDGE_FILE

#include "include.h"

class Fridge{
public:
	static bool AddIngredient(string name, int quantity, string qualityType);
	static bool RemoveIngredient(string name);
	static bool ListIngredient();
	static bool SearchReceipe();

	static const string fridge_f; //location of fridge File

};
#endif FRIDGE_FILE