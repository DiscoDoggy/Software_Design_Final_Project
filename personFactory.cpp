#include "personFactory.hpp"
#include <fstream>
#include <sstream>
#include <vector>
vector<Person*>PersonFactory::Parse(BookCollection* passedInCollection) {
	ifstream inFS;
	vector<Person*> allLibPersons;
	inFS.open("allLibraryPeople.txt");

	if (!inFS.is_open()) {
		cout << "File for loading people could not open" << endl;
		exit(-1);
	}

	string type = "";
	string username = "";
	string password = "";
	string borrowedBooks = "";
	string pastBorrowed = "";
	string stringPartial = "";
	double loadDebt = 0.0;
	vector<string>currBorrowedBooks;
	vector<string> passedBorrowedBooks;

	while(inFS) {
		currBorrowedBooks.clear();
		passedBorrowedBooks.clear();

		inFS >> type;

		if (type == "admin") {
			if(!inFS) {
				break;
			}
			
			inFS >> username;
			inFS >> password;

			Admin* newAdmin = new Admin(username, password);
			allLibPersons.push_back(newAdmin);			
		}

		else if (type == "user") {
			if(!inFS) {
				break;
			}

			inFS >> username;
			inFS >> password;

			getline(inFS, borrowedBooks);
			stringstream ss(borrowedBooks);

			while(ss.good()) {
				getline(ss, stringPartial, ',');
				currBorrowedBooks.push_back(stringPartial);
			}

			getline(inFS, pastBorrowed);
			stringstream myStringStream(pastBorrowed);
			
			while(myStringStream.good()) {
				getline(myStringStream, stringPartial, ',');
				passedBorrowedBooks.push_back(stringPartial);
			}

			inFS >> loadDebt;

			User* newUser = new User(username, password, loadDebt);
			
			for(int i = 0; i < currBorrowedBooks.size(); i++) {
				newUser->borrow_book(currBorrowedBooks.at(i), passedInCollection);
			}

			for(int i = 0; i < passedBorrowedBooks.size(); i++) {
				newUser->addToBorrowHistory(passedBorrowedBooks.at(i), passedInCollection);
			}

			allLibPersons.push_back(newUser);
			
				
		}


	}

	inFS.close();
	return allLibPersons;

} 



