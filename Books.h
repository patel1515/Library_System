#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

class Books : public Library
{
public:
	Books();
	Books(int i, string n, bool s, string c, string a);
	virtual ~Books() {};
	void setData(int i, string n, bool s, string c, string a);
	virtual void setAuthor_name(string a);
	virtual string getAuthor_name() const;
	void print() const;

private:
	string Author_name;
};

#endif 

