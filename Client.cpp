//
//  main.cpp
//  asd
//
//  Created by Akshit Patel on 12/8/19.
//  Copyright © 2019 Akshit Patel. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Library.h"
#include "Books.h"
#include "Journals.h"
#include "Magazines.h"

using namespace std;

bool checkName(string n, vector<Library*>& list)
{
    bool found = false;
    for (int i = 0; i < list.size(); i++)
    {
        if ((*list[i]).getName() == n)
        {
            found = true;
            return found;
        }
    }
    return found;
}

bool checkAuthor(string n, vector<Library*>& list)
{
    bool found = false;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->getCategory() == "Book" && dynamic_cast<Books*>(list[i])->getAuthor_name() == n) {
            found = true;
            return found;
        }
    }
    return found;
}

bool checkCategory(string c, vector<Library*>& list)
{
    bool check = false;
    for (int i = 0; i < list.size(); i++)
        if ((*list[i]).getCategory() == c)
        {
            check = true;
            (*list[i]).print();
        }
    return check;
}

int main()
{
    string trash = "", name, Aname, Iname, Rname;
    int id, vol, in;
    bool found;
    char action = 0, choice = 0, catChoice = 0;
    vector<Library*> content;

    content.push_back(new Books(1,"Twilight", true, "Book", "Stephenie Meyer"));
    content.push_back(new Books(2, "The Kite Runner", true, "Book", "Khaled Hosseini"));
    content.push_back(new Books(3, "New Moon", true, "Book", "Stephenie Meyer"));
    content.push_back(new Books(4, "Life Of Pi", true, "Book", "Yann Martel"));
    content.push_back(new Books(5, "Catching Fire", true, "Book", "Suzanne Collins"));
    content.push_back(new Journals(6, "Engineering Science and Technology", true, "Journal", 40));
    content.push_back(new Journals(7, "European Journal of Computational Mechanics", true, "Journal", 22));
    content.push_back(new Journals(8, "The Journal for Engineering Education", true, "Journal", 107));
    content.push_back(new Journals(9, "Advanced Materials", true, "Journal", 30));
    content.push_back(new Journals(10, "Nature Nanotechnology", true, "Journal", 13));
    content.push_back(new Magazines(11, "Wired", true, "Magazine", 6));
    content.push_back(new Magazines(12, "The New Yorker", true, "Magazine", 4));
    content.push_back(new Magazines(13, "Consumer Reports", true, "Magazine", 8));
    content.push_back(new Magazines(14, "Business Week", true, "Magazine", 2));
    content.push_back(new Magazines(15, "Cooking Light", true, "Magazine", 3));

    cout << setfill('*') << setw(110) << "\n";
    cout << setfill('*') << setw(66) << " Name: Ak Patel " << setfill('*') << setw(44) << "\n";
    cout << setfill('*') << setw(60) << " Access ID: gx2475 " << setfill('*') << setw(50) << "\n";
    cout << setfill('*') << setw(70) << " Welcome to Ak's Library " << setfill('*') << setw(40) << "\n";
    cout << setfill('*') << setw(110) << "\n";
    
    while (true)
    {
        try
        {
            cout << "\n";
            cout << setfill('*') << setw(20) << "\n";
            cout << "1. Search Catalog" << endl;
            cout << "2. Check out" << endl;
            cout << "3. Return" << endl;
            cout << "4. Add a new item" << endl;
            cout << "5. Exit" << endl;

            cout << "Please select: ";
            cin >> action;
            getline(cin, trash);
            cout << setfill('*') << setw(20) << "\n";
            cout << "\n";

            switch (action)
            {
            case '1':
                cout << "How do you want to search:" << endl;
                cout << "1. Search by name." << endl;
                cout << "2. Search spicific book by using author name." << endl;
                cout << "3. Search by category." << endl;
                cout << "4. List entire catalog." << endl;
                cout << "Enter your option: ";
                cin >> choice;
                cout << endl;

                if (choice < '1' || choice > '4')
                    throw "Invalid input. Try again.";

                if (choice == '1')
                {
                    cout << "Enter the name: ";
                    getline(cin, trash);
                    getline(cin, name);
                
                    if (checkName(name, content))
                    {
                        for (int i = 0; i < content.size(); i++)
                            if (content[i]->getName() == name)
                            {
                                content[i]->print();
                            }
                    }

                    else
                        cout << "Item not found" << endl;
                }

                else if (choice == '2')
                {
                    cout << "Enter the name of the author: ";
                    getline(cin, trash);
                    getline(cin, Aname);

                    if (checkAuthor(Aname, content))
                    {
                        for (int i = 0; i < content.size(); i++)
                            if (content[i]->getCategory() == "Book" && dynamic_cast<Books*>(content[i])->getAuthor_name() == Aname)
                            {
                                content[i]->print();
                            }
                    }

                    else
                        cout << "Item not found." << endl;
                }

                else if (choice == '3')
                {
                    cout << "Which catagory are you looking for:" << endl;
                    cout << "1. Book." << endl;
                    cout << "2. Journal." << endl;
                    cout << "3. Magazine." << endl;
                    cout << "Your selection: ";
                    cin >> catChoice;
                    cout << endl;

                    if (catChoice < '1' || catChoice > '3')
                        throw "Invalid input. Try again.";

                    if (catChoice == '1')
                    {
                        checkCategory("Book", content);
                    }
                    else if (catChoice == '2')
                    {
                        checkCategory("Journal", content);
                    }
                    else if (catChoice == '3')
                    {
                        checkCategory("Magazine", content);
                    }
                }

                else if (choice == '4')
                {
                    checkCategory("Book", content);
                    checkCategory("Journal", content);
                    checkCategory("Magazine", content);
                }

                break;

            case '2':
                cout << "Enter the name of the item you want to check out: ";
                getline(cin, Iname);

                if (checkName(Iname, content))
                {
                    for (int i = 0; i < content.size(); i++) {
                        if ((*content[i]).getName() == Iname)
                        {
                            if (content[i]->getStatus() == false)
                            {
                                cout << "Item has already been checked out." << endl;
                            }
                            else
                            {
                                content[i]->setStatus(false);
                                cout << Iname << " has been checked out." << endl;
                            }
                            
                        }
                    }
                }
                else
                {
                    cout << "Item not found. " << endl;
                }
                break;

            case '3':
                cout << "What is the name of the item you want to return: ";
                getline(cin, Rname);

                if (checkName(Rname, content))
                {
                    for (int i = 0; i < content.size(); i++) {
                        if ((*content[i]).getName() == Rname)
                        {
                            if (content[i]->getStatus() == true)
                            {
                                cout << "Item has not been checked out." << endl;
                            }
                            else
                            {
                                content[i]->setStatus(true);
                                cout << Rname << " has been returned." << endl;
                            }

                        }
                    }
                    break;
                }
                else
                {
                    cout << "Item not found. " << endl;
                    break;
                }

            case '4':
                cout << "What is the name of the item you want to add: ";
                getline(cin, name);

                cout << "What is the id of the item: ";
                cin >> id;

                if (!cin)
                    throw "Id has to be a number. Try again.";

                cout << "Which catagory does the item fall under:" << endl;
                cout << "1. Book." << endl;
                cout << "2. Journal." << endl;
                cout << "3. Magazine." << endl;
                cout << "Your selection: ";
                cin >> catChoice;
                cout << endl;


                if (catChoice < '1' || catChoice > '3')
                    throw "Invalid input. Try again.";

                if (catChoice == '1')
                {
                    cout << "What is the name of the author name: ";
                    getline(cin, trash);
                    getline(cin, Aname);

                    bool Bfound = checkName(name, content);

                    if (Bfound == false)
                    {
                        content.push_back(new Books(id, name, true, "Book", Aname));
                        cout << "Book added. " << endl;
                    }
                    else
                    {
                        cout << "Book already exists." << endl;
                    }
                }

                else if (catChoice == '2')
                {
                    cout << "What is the volume of the journal: ";
                    cin >> vol;

                    if (!cin)
                        throw "Volume has to be a number. Try again.";

                    bool Jfound = checkName(name, content);

                    if (Jfound == false)
                    {
                        content.push_back(new Journals(id, name, true, "Book", vol));
                        cout << "Journal added. " << endl;
                    }
                    else
                    {
                        cout << "Journal already exists." << endl;
                    }
                }

                else if (catChoice == '3')
                {
                    cout << "What is the issue number of the magazine: ";
                    cin >> in;

                    if (!cin)
                        throw "Issue number has to be a number. Try again.";

                    bool Mfound = checkName(name, content);

                    if (Mfound == false)
                    {
                        content.push_back(new Magazines(id, name, true, "Book", in));
                        cout << "Magazine added. " << endl;
                    }
                    else
                    {
                        cout << "Magazine already exists." << endl;
                    }
                }
                break;

            case '5':
                cout << "Thanks for using my program." << endl;
                cout << "Have a wonderful day." << endl;
                return 0;
            default:
                cout << "Invalid Input. Try again.\n";
            }
        }
        catch (exception e)
        {
            cout << e.what() << endl;
            cin.clear();
            getline(cin, trash);
        }
    }

    

    
}

