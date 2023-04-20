#include "controller.h"
#include <QDebug>

/*****************************************************************//**
 * \file   controller.cpp
 * \brief  Controller class takes a repository of multiple Electronics pointers and does all operations
 * 
 * \author Ioan
 * \date   May 2022
 *********************************************************************/
/**
 * Adds an element in repository.
 * 
 * \param a
 */
void controller::add(Electronics* a)
{
	arr.addElectronics(a);
	action z(a, "Add", arr.getLength());
	undo.push(z);

}
/**
 * removes an element from the repository at a given index.
 * 
 * \param index
 */
void controller::remove(int index){
	
	Electronics* x = arr.get(index);
	arr.remove(index);
	action z(x, "Remove", index);
	undo.push(z);
}
/**
 * removes the last element from the repository.
 * 
 */
void controller::removeLast()
{
	Electronics* x = arr.get(arr.getLength()-1);
	action z(x, "Remove",arr.getLength()-1);
	undo.push(z);
	arr.popBack();
	
}
/**
 * displays all the elements of the repository.
 * 
 */
void controller::display()
{
	cout << arr;
}
/**
 * returns the dimensions of the repository.
 * 
 * \return 
 */
int controller::dimension()
{
	return arr.getLength();
}
/**
 * reads from the csv file.
 * 
 * \param nr(it is used to know how many of each Electronics object there are
 */
void controller::readFile(int nr)//code is a little pompous but it works
{
	string line, word;
	vector <string> row;
	vector<vector<string>> content;
    ifstream f("InitialRepo.txt");
	if (f.is_open()) {
		while (getline(f, line)) {
			row.clear();
			stringstream str(line);
			while (getline (str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	//i put all the words in a string matrix;
	f.close();
	int k = 0;
	string atr1,atr6;
	float atr2, atr3;
	int atr4, atr5;
	for (int i = 0; i < content.size(); i++)
	{
		if (k < nr) {
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << content[i][j] << " ";
				if (j == 0)atr1 = content[i][j];
				if (j == 1)atr2 = stof(content[i][j]);
				if (j == 2)atr3 = stof(content[i][j]);
				if (j == 3)atr4 = stoi(content[i][j]);
				if (j == 4)atr5 = stoi(content[i][j]);
			}
			arr.addElectronics(new Phone(atr1, atr2, atr3, atr4, atr5));
		}
		if (k < 2*nr && k>=nr) {
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << content[i][j] << " ";
				if (j == 0)atr1 = content[i][j];
				if (j == 1)atr2 = stof(content[i][j]);
				if (j == 2)atr3 = stof(content[i][j]);
				if (j == 3)atr4 = stoi(content[i][j]);
				if (j == 4)atr5 = stoi(content[i][j]);
			}
			arr.addElectronics(new Tablet(atr1, atr2, atr3, atr4, atr5));
		}
		if (k < 3 * nr && k >= 2*nr) {
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << "da";
				//cout << content[i][j] << " ";
				if (j == 0)atr1 = content[i][j];
				if (j == 1)atr2 = stof(content[i][j]);
				if (j == 2)atr3 = stof(content[i][j]);
				if (j == 3)atr4 = stoi(content[i][j]);
				if (j == 4)atr6 = content[i][j];
			}
			arr.addElectronics(new Leptop(atr1, atr2, atr3, atr4, atr6));
		}
		if (k < 4 * nr && k >= 3 * nr) {
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << content[i][j] << " ";
				if (j == 0)atr1 = content[i][j];
				if (j == 1)atr2 = stof(content[i][j]);
				if (j == 2)atr3 = stof(content[i][j]);
				if (j == 3)atr4 = stoi(content[i][j]);
				
			}
			arr.addElectronics(new Processor(atr1, atr2, atr3, atr4));
		}
		if (k < 5 * nr && k >= 4 * nr) {
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << content[i][j] << " ";
				if (j == 0)atr1 = content[i][j];
				if (j == 1)atr2 = stof(content[i][j]);
				if (j == 2)atr3 = stof(content[i][j]);
				if (j == 3)atr4 = stoi(content[i][j]);
				
			}
			arr.addElectronics(new GPU(atr1, atr2, atr3, atr4));
		}
		k++;
		//cout << k;
	}
	//cout << arr;
}
/**
 * writes the repository into a csv file.
 * 
 */
void controller::writeFile()
{
	ofstream f("InitialRepo.txt");
	for (int i = 0; i < arr.getLength(); i++) {
		f << arr.get(i)->ToCSV() << endl;

	}
	f.close();


}
/**
 * edits an element from the repository at a given index.
 * 
 * \param index
 */
void controller::edit(int index)
{
	arr.edit(index);
}
/**
 * undos last action.
 * 
 */
void controller::undo1()
{

	if (!undo.empty()) {
		if (undo.top().getActiune() == "Add") {
			action z(undo.top().getElem(), undo.top().getActiune(), undo.top().getIndex());
			redo.push(z);

			arr.popBack();



		}
		if (undo.top().getActiune() == "Remove") {
			action z(undo.top().getElem(), undo.top().getActiune(), undo.top().getIndex());
			redo.push(z);

			arr.addElectronics(undo.top().getElem());


		}
        undo.pop();
	}
	else { cout << "You can't undo!"; }
}
/**
 * redoes last action.
 * 
 */
void controller::redo1()
{
	//cout << redo.top().getActiune() << endl;
	//cout << redo.top().getIndex()<<endl;
	//cout << redo.top().getElem();
	if (!redo.empty()) {
		if (redo.top().getActiune() == "Add") {
			arr.addElectronics(redo.top().getElem());
			
		}
		if (redo.top().getActiune() == "Remove") {
			arr.remove(redo.top().getIndex());
			
		}
		redo.pop();
	}
	else { cout << "You can't redo!"; }
	

}


