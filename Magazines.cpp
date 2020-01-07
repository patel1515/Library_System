#include "Magazines.h"
#include "iomanip"

Magazines::Magazines()
{
	setIssue_Number(0);
}

Magazines::Magazines(int i, string n, bool s, string c, int IN)
	: Library(i,n,s,c)
{
	setIssue_Number(IN);
}

void Magazines::setData(int i, string n, bool s, string c, int IN)
{
	Library::setData(i, n, s, c);
	Issue_Number = IN;
}

void Magazines::setIssue_Number(int IN)
{
	Issue_Number = IN;
}

int Magazines::getIssue_Number() const
{
	return Issue_Number;
}

void Magazines::print() const
{
	Library::print();
	cout << "Issue number: " << getIssue_Number() << endl;
	cout << setfill('-') << setw(45) << "\n";
}
