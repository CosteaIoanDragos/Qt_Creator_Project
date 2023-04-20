#pragma once
#include "Repo.h"
#include <fstream>
#include <stack>

/**
 * Action class 
 * it takes an electronic object, a string (name of the action)and an index.
 */
class action {
public:
	action(Electronics* a1, string z, int i) { a = a1, actiune = z; index = i; };
	Electronics* getElem() { return a; }
	string getActiune() { return actiune; }
	int getIndex() { return index; }
protected:
	Electronics* a;
	string actiune;
	int index;
};


/**
 * Controller class ,manages all .
 */
class controller
{public:
	void add(Electronics* a);
	void remove(int index);
	void removeLast();
	void display();
	int dimension();
	void readFile(int nr);//nr-How many of each time all in order(first phones,tablets,leptops,cpu ,gpu
	void writeFile();
	void edit(int index);
	void undo1();
	void redo1();
    string getElementString(int i){

        return arr.getElementStr(i);
    }

private:
	Repo arr;
	stack<action>undo;
	stack<action>redo;
};


