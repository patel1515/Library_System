#ifndef JOURNALS_H
#define JOURNALS_H
#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

class Journals : public Library
{
public:
	Journals();
	Journals(int i, string n, bool s, string c, int v);
	virtual ~Journals() {};
	void setData(int i, string n, bool s, string c, int v);
	void setVolume(int v);
	int getVolume() const;
	void print() const;

private:
	int Volume;
};

#endif 
