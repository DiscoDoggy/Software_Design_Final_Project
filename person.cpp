#include "person.hpp"

string Person::getDerivedClassType() {
	return derivedClassType;

}

Person::~Person() {
	cout << "Person destructor" << endl;
}

void Person::display_books(BookCollection* bookC) {
  char choice;
  TitleAZ a;
  TitleZA b;
  AuthorAZ c;
  AuthorZA d;
  while ((choice != 'Q') && (choice != 'q')) {
    cout << "Pick sorting method:" << endl;
    cout << "(1) Alphabetical by book title" << endl;
    cout << "(2) Reverse-alphabetical by book title" << endl;
    cout << "(3) Alphabetical by author" << endl;
    cout << "(4) Reverse-alphabetical by author" << endl;
    
    cout << "(Q) Return without sorting" << endl;
    cin >> choice;
    if (choice == '1') {
      bookC->sort_books(&a);
    }
    if (choice == '2') {
      bookC->sort_books(&b);
    }
    if (choice == '3') {
      bookC->sort_books(&c);
    }
    if (choice == '4') {
      bookC->sort_books(&d);
    }
  }
  return;
}

bool Person::doesUsrMatchPassword(string passedInUsername, string passedInPassword) {
	if(passedInUsername == username && passedInPassword == password) {
                return true;
	}
	
	else {
                return false;
        }
  }

string Person::getUsername() {

	return username;

}


string Person::getPassword() {
	return password;

}


