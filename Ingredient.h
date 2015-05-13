#ifndef INGREDIENT_FILE
#define INGREDIENT_FILE

#include "include.h"
using namespace std;

class Ingredient : public IComparable
{
private:
	string name;
	int quantity;
	string quantityType;
public:
	Ingredient() :name(""), quantity(0), quantityType(""){} //default constructor;
	Ingredient(string n, int q, string qT):name(n),quantity(q),quantityType(qT){}
	//GETTERS
	string getName(void) const { return name ;};
	int getQuantity(void) const { return quantity; };
	string getQuantityType(void) const { return quantityType; };

	//SETTERS
	void setName(string n) { name = n; };
	void setQuantity(int q) { quantity = q; };
	void setQuantityType(string qT) { quantityType = qT; };

	bool operator ==(const IComparable& theOther);
	Ingredient operator =(const Ingredient& theOther);

	friend istream &operator>>(istream  &in, ostream& out); 
	friend string &operator>>(string  &line, Ingredient& ingredient);
	friend ostream &operator<<(ostream  &out,const Ingredient& theOther);
};


#endif INGREDIENT_FILE