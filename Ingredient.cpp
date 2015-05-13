#include "include.h"

using namespace std;

bool Ingredient::operator ==(const IComparable& theOther){
	bool r = false;
	if (name == ((Ingredient&)theOther).getName() &&
		quantity <= ((Ingredient&)theOther).getQuantity() &&
		quantityType == ((Ingredient&)theOther).getQuantityType())
	{
		r = true;
	}
	return r;
}

Ingredient Ingredient::operator =(const Ingredient& theOther){

	if (this != &theOther){ // allow to avoid error with auto assignement
		name = ((Ingredient&)theOther).getName();
		quantity = ((Ingredient&)theOther).getQuantity();
		quantityType = ((Ingredient&)theOther).getQuantityType();
	}
	return *this;
}

istream &operator>>(istream  &in, ostream& out){
	vector<Ingredient> ingredients; 
	string line,delimiter = ";";
	while (getline(in, line)) {
		vector<string> v;
		split(line, ';', v);

		//allow to convert string to int
		string::size_type sz;   // alias of size_t
		int quantity = stoi(v[1], &sz);

		ingredients.push_back(Ingredient(v[0], quantity, v[2]));
	}

	int nbLines = ingredients.size();
	for (int i = 0; i < nbLines; i++)
	{
		out << "Name : " << ingredients.back().getName()
			<< " - Quantity : " << ingredients.back().getQuantity()
			<< " - Quantity Type : " << ingredients.back().getQuantityType() << endl;
		ingredients.pop_back();//remove the last case
	}
	return in;
}
string &operator>>(string  &line, Ingredient& ingredient){
	string delimiter = ";";
	int quantity, nbElement = 0;
	vector<string> v;
	split(line, ';', v);

	//allow to convert string to int
	string::size_type sz;   // alias of size_t
	quantity = stoi(v[1], &sz);

	ingredient.setName(v[0]);
	ingredient.setQuantity(quantity);
	ingredient.setQuantityType(v[2]);
	return line;
}
ostream &operator<<(ostream  &out, const Ingredient& theOther){
	out << theOther.getName() << ";" << theOther.getQuantity() << ";" << theOther.getQuantityType() << ";\n";
	return out;
}
