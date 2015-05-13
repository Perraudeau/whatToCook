#include "include.h"
using namespace std;

bool Receipe::operator ==(const IComparable& theOther){
	bool r = false;
	if (name == ((Receipe&)theOther).getName() &&
		difficulty == ((Receipe&)theOther).getDifficulty() &&
		time == ((Receipe&)theOther).getTime() && 
		ingredients == ((Receipe&)theOther).getIngredients())
	{
		r = true;
	}
	return r;
}
Receipe Receipe::operator =(const Receipe& theOther){

	if (this != &theOther){ // allow to avoid error with auto assignement
		name = ((Receipe&)theOther).getName();
		difficulty = ((Receipe&)theOther).getDifficulty();
		time = ((Receipe&)theOther).getTime();
		ingredients = ((Receipe&)theOther).getIngredients();
	}
	return *this;
}
ostream &operator<<(ostream  &out, const Receipe& theOther){
	out << theOther.getName() << ";" << theOther.getDifficulty() << ";" << theOther.getTime() << ";"; // the informations of the receipe
	Ingredient* ingredients = new Ingredient[50];
	ingredients = theOther.getIngredients();
	for (int i = 0; i < 50; i++)
	{
		if (!ingredients[i].getName().empty()){
			out << ingredients[i].getName() << ";" << ingredients[i].getQuantity() << ";" << ingredients[i].getQuantityType() << ";";
		}
	}
	out << endl;
	delete[] ingredients; //freed memory
	ingredients = new Ingredient[50]; //reinitalize memory
	return out;
}
string &operator>>(string  &line, Receipe& receipe){
	string delimiter = ";";
	Ingredient* ingredients = new Ingredient[50];
	int quantity,nbElement = 0;
	vector<string> v;
	split(line, ';', v);
	for (unsigned int i = 3; i < v.size()-1; i = i + 3){
		//allow to convert string to int
		string::size_type sz;   // alias of size_t
		quantity = stoi(v[i+1], &sz);
		ingredients[nbElement] = Ingredient(v[i], quantity, v[i + 2]);
		nbElement++;
	}
	receipe.setName(v[0]);
	receipe.setDifficulty(v[1]);
	receipe.setTime(v[2]);
	receipe.setIngredients(ingredients);

	return line;
}
