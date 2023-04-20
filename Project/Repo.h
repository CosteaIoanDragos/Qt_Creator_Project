#pragma once
#include "Electronics.h"
#include <vector>
#include <fstream>
/**
 * Repository.
 */
class Repo
{public:
	void addElectronics(Electronics* a);
	vector<Electronics*>getAll() { return data; }
	Electronics* get(int index) { return data[index]; }
	friend ostream& operator<<(ostream& s, const Repo& arr);
	void popBack();
	void remove(int index);
	void read();
	inline  int getLength() const { return data.size(); }
	void edit(int index);
    string getElementStr(int i){return  data[i]->ToString();}

private:
	vector<Electronics*>data;
};

