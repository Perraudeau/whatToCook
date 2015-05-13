#ifndef RECEIPE_FILE
#define RECEIPE_FILE

#include "include.h"
using namespace std;

class Receipe: public IComparable
{
	private:
		string name;
		string difficulty;
		string time;
		Ingredient* ingredients;
	public:
		Receipe() :name(""), difficulty(""), time(""), ingredients(NULL){}
		Receipe(string n, string d, string t, Ingredient* i) :name(n), difficulty(d), time(t), ingredients(i){}
		~Receipe(){ delete[] ingredients; } //destructor
		//GETTERS
		string getName(void) const { return name; };
		string getDifficulty(void) const { return difficulty; };
		string getTime(void) const { return time; };
		Ingredient* getIngredients(void) const { return ingredients; };

		//SETTER
		void setName(string n) { name = n ; };
		void setDifficulty(string d) { difficulty = d; };
		void setTime(string t) { time = t; };
		void setIngredients(Ingredient* i) { ingredients = i; };

		bool operator ==(const IComparable& theOther);
		Receipe operator =(const Receipe& theOther);

		friend string &operator>>(string  &line, Receipe& receipe);
		friend ostream &operator<<(ostream  &out, const Receipe& theOther);
};


#endif RECEIPE_FILE