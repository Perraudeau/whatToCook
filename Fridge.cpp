#include "include.h"

const string Fridge::fridge_f = "fridge.txt"; //location of the fridge file

bool Fridge::AddIngredient(string name, int quantity, string qualityType){

	ofstream fridgeFile(fridge_f, ios_base::app);//opening in mode append
	try{
		if (!fridgeFile){
			throw exception("Impossible to open the file : ");
		}
	Ingredient i(name, quantity, qualityType);//creation of an instance of an ingredient
	fridgeFile << i; //operator overload to push ingredient in the file
	fridgeFile.close();
	}
	catch (exception e){
		cerr << "ERROR : " << e.what() << fridge_f << endl;
	}
	return true;
}
bool Fridge::RemoveIngredient(string name){
	bool r = false;
	string line; //current line used
	string token; //name of the ingredient in the input file

	ifstream fridgeFileInput(fridge_f); //input file
	ofstream fridgeFileOutput("fridge.tmp"); // temporary file
	try{
		if (!fridgeFileInput){
			throw exception("Impossible to open the file : ");
		}
		//for each line, if the first argument is not the name asked, the line is write in the temporary file.
		while (getline(fridgeFileInput, line))
		{
			token = line.substr(0, line.find(";")); //take the first argument, here the name of the ingredient
			if (token != name)
			{
				fridgeFileOutput << line + "\n";

			}
			else{
				r = true;
			}
		}

		fridgeFileInput.close();
		fridgeFileOutput.close();

		//Deleting of the old file and rename of the temporary file
		if (fridgeFileOutput) {
			remove("fridge.txt");
			rename("fridge.tmp", "fridge.txt");
		}
		else {
			cerr << "Write error on output" << endl;
		}
	}
	catch (exception e){
		cerr << "ERROR : " << e.what() << fridge_f << endl;
	}
	return r;
}
bool Fridge::ListIngredient(){
	ifstream fridgeFile(fridge_f);
	try{
		if (!fridgeFile){
			throw exception("Impossible to open the file : ");
		}
	//operator overloadind from istream(fridge.txt) to ostream(cout here)
	fridgeFile >> cout;
	fridgeFile.close();
	}
	catch (exception e){
		cerr << "ERROR : " << e.what() << fridge_f << endl;
	}
	return true;
}
bool Fridge::SearchReceipe(){
	cout << "--------------------------------------------" << endl;
	cout << "You can cook : " << endl;
	//First part, creation of an array of objects for boths files
	//Receipe part
	ifstream cookBookFile(CookBook::cookBook_f); //CookBookFile
	string lineReceipe;
	Receipe* receipes[50];
	Receipe receipe;
	int iReceipe = 0;
	try{
		if (!cookBookFile){
			throw exception("Impossible to open the file : cookBook.txt");
		}
	while (getline(cookBookFile, lineReceipe)) {
		if (!lineReceipe.empty()){
			lineReceipe >> receipe;
			receipes[iReceipe] = new Receipe(receipe);
			iReceipe++;
		}
	}
	cookBookFile.close();
	
	//Fridge part
	ifstream fridgeFile(Fridge::fridge_f); //Fridge file
	string lineIngredient;
	Ingredient* ingredients = new Ingredient[50];
	Ingredient ingredient;
	int iIngredient = 0;
	if (!fridgeFile){
		throw exception("Impossible to open the file : fridgeFile.txt");
	}
	while (getline(fridgeFile, lineIngredient)) {
		if (!lineIngredient.empty()){
			lineIngredient >> ingredient;
			ingredients[iIngredient] = ingredient;
			iIngredient++;
		}
	}
	fridgeFile.close();
	//Seconde part
	int nbElementReceipe;
	int possible = 0;
	//for each receipe
	for (int i = 0; i < iReceipe; i++)
	{
		nbElementReceipe = 0;

		Ingredient* listIngredientsReceipe = new Ingredient[50];
		listIngredientsReceipe = receipes[i]->getIngredients();
		//for each ingredient of one receipe
		for (int j = 0; j < 50; j++)
		{
			if (!listIngredientsReceipe[j].getName().empty()){
				nbElementReceipe++;
				//for each ingredient of fridge
				for (int k = 0; k < iIngredient; k++){
					if (listIngredientsReceipe[j] == ingredients[k]){
						possible++;
					}
				}
			}
		}
		if (possible == nbElementReceipe){
			cout << "--------------------------------------------" << endl;
			cout << " Name : " << receipes[i]->getName() << endl;
			cout << " Difficulty : " << receipes[i]->getDifficulty() << endl;
			cout << " Time : " << receipes[i]->getTime() << endl;
			cout << "--------------------------------------------" << endl;
		}
		possible = 0;

		delete[] listIngredientsReceipe; //freed memory
		listIngredientsReceipe = new Ingredient[50]; //reinitalize memory

		delete[] ingredients; //freed memory
		ingredients = new Ingredient[50]; //reinitalize memory
	}
	}
	catch (exception e){
		cerr << "ERROR : " << e.what() << endl;
	}
	return true;
}