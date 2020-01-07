#include "Journals.h"
#include <iomanip>

Journals::Journals()
{
	setVolume(0);
}

Journals::Journals(int i, string n, bool s, string c, int v)
	: Library(i, n, s, c)
{
	setVolume(v);
}

void Journals::setData(int i, string n, bool s, string c, int v)
{
	Library::setData(i, n, s,c);
	setVolume(v);
}

void Journals::setVolume(int v)
{
	Volume = v;
}

int Journals::getVolume() const
{
	return Volume;
}

void Journals::print() const
{
	Library::print();
	cout << "Volume: " << getVolume() << endl;
	cout << setfill('-') << setw(45) << "\n";
}
