#ifndef COOKBOOK_FILE
#define COOKBOOK_FILE

#include "include.h"
using namespace std;

class CookBook{

public:
	static bool AddReceipe(string name, string difficulty, string time, Ingredient* ingredients);
	static bool RemoveReceipe(string name); 
	static bool ListReceipe();

	static const string cookBook_f; //location of cookBook file

};

#endif COOKBOOK_FILE