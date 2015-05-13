#include "include.h"

const string CookBook::cookBook_f = "cookBook.txt"; //location of the cookBook file

bool CookBook::AddReceipe(string name, string difficulty, string time, Ingredient* ingredients){
	
	ofstream cookBookFile(cookBook_f, ios_base::app);//opening in mode append
	try{
		if (!cookBookFile){
			throw exception("Impossible to open the file : ");
		}
		Receipe r(name, difficulty, time, ingredients);//creation of an instance of a receipe
		cookBookFile << r; //operator overload to push receipe in the file
		cookBookFile.close();
	}catch (exception e){
		cerr << "ERROR : " << e.what() << cookBook_f << endl;
	}
	return true;
}

bool CookBook::RemoveReceipe(string name){
	bool r = false;
	string line; //current line used
	string token; //name of the ingredient in the input file

	ifstream cookBookFileInput(cookBook_f); //input file
	ofstream cookBookFileOutput("cookBook.tmp"); // temporary file
	try{
		if (!cookBookFileInput){
			throw exception("Impossible to open the file : ");
		}
		//for each line, if the first argument is not the name asked, the line is write in the temporary file.
		while (getline(cookBookFileInput, line))
		{
			token = line.substr(0, line.find(";")); //take the first argument, here the name of the ingredient
			if (token != name)
			{
				cookBookFileOutput << line + "\n";

			}
			else{
				r = true;
			}
		}
		cookBookFileInput.close();
		cookBookFileOutput.close();

		//Deleting of the old file and rename of the temporary file
		if (cookBookFileOutput) {
			remove("cookBook.txt");
			rename("cookBook.tmp", "cookBook.txt");
		}
		else {
			cerr << "Write error on output" << endl;
		}
	}catch (exception e){
		cerr << "ERROR : " << e.what() << cookBook_f << endl;
	}
	return r;
}

bool CookBook::ListReceipe(){

	ifstream cookBookFile(cookBook_f);
	vector<Receipe> receipes;
	string line, delimiter = ";";
	Ingredient* ingredients = new Ingredient[50];
	Receipe receipe;
	int nbElement = 0;

	try{
		if (!cookBookFile){
			throw exception("Impossible to open the file : ");
		}
		while (getline(cookBookFile, line)) {

			//Receip part
			line >> receipe;
			ingredients = receipe.getIngredients();
			cout << "--------------------------------------------" << endl;
			cout << " Name : " << receipe.getName() << endl;
			cout << " Difficulty : " << receipe.getDifficulty() << endl;
			cout << " Time : " << receipe.getTime() << endl;
			cout << "--------------------------------------------" << endl;

			//ingredients part
			for (int i = 0; i < 50; i++)
			{
				if (!ingredients[i].getName().empty()){
					cout << " Name : " << ingredients[i].getName()
						<< " - Quantity : " << ingredients[i].getQuantity()
						<< " - Quantity Type : " << ingredients[i].getQuantityType() << endl;
				}
			}
		}

	}catch (exception e){
		cerr << "ERROR : " << e.what() << cookBook_f << endl;
	}	
	delete[] ingredients;
	ingredients = new Ingredient[50];

	cookBookFile.close();
	return true;
}