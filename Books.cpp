#include "Books.h"
#include <iomanip>

Books::Books()
{
	setAuthor_name("Unknown");
}

Books::Books(int i, string n, bool s, string c, string a)
	 : Library(i, n, s, c)
{
	setAuthor_name(a);
}

void Books::setData(int i, string n, bool s, string c, string a)
{
	Library::setData(i, n, s, c);
	setAuthor_name(a);
}

void Books::setAuthor_name(string a)
{
	Author_name = a;
}

string Books::getAuthor_name() const
{
	return Author_name;
}

void Books::print() const
{
	Library::print();
	cout << "Author name: " << getAuthor_name() << endl;
	cout << setfill('-') << setw(45) << "\n";
}
