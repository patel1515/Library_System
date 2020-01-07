#include "Library.h"
#include <iomanip>

Library::Library()
{
	setData(0, "Unknown", "Not Available", "Category");
}

Library::Library(int i, string n, bool s, string c)
{
	ID = i;
	Name = n;
	Status = s;
	Category = c;
}

void Library::setData(int i, string n, bool s,string c)
{
	ID = i;
	Name = n;
	Status = s;
	Category = c;
}

void Library::setID(int i)
{
	ID = i;
}

void Library::setName(string n)
{
	Name = n;
}

void Library::setStatus(bool s)
{
	Status = s;
}

void Library::setCategory(string c)
{
	Category = c;
}

int Library::getID() const
{
	return ID;
}

string Library::getName() const
{
	return Name;
}

bool Library::getStatus() const
{
	return Status;
}

string Library::getCategory() const
{
	return Category;
}

void Library::print() const
{
	cout << "\n";
	cout << setfill('-') << setw(45) << "\n";
	cout << "Name: " << getName() << endl;
	cout << "Category: " << getCategory() << endl;
	cout << "ID: " << getID() << endl;
	
	if (Status)
		cout << "Status: Checked In\n";
	else
		cout << "Status: Checked Out\n";
}
