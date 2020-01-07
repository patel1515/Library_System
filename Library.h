#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>

using namespace std;

class Library
{
public:
	Library();
	Library(int i, string n, bool s, string c);
	virtual ~Library() {};
	void setData(int i, string n, bool s, string c);
	void setID(int i);
	void setName(string n);
	void setStatus(bool s);
	void setCategory(string c);
	int getID() const;
	string getName() const;
	bool getStatus() const;
	string getCategory() const;
	virtual void print() const;

private:
	int ID;
	string Name;
	bool Status;
	string Category;
};

#endif 