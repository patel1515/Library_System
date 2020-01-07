#ifndef MAGAZINES_H
#define MAGAZINES_H
#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

class Magazines : public Library
{
public:
	Magazines();
	Magazines(int i, string n, bool s, string c, int IN);
	virtual ~Magazines() {};
	void setData(int i, string n, bool s, string c, int IN);
	void setIssue_Number(int IN);
	int getIssue_Number() const;
	void print() const;

private:
	int Issue_Number;
};

#endif 

