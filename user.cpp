#include "person.hpp"
#include "user.hpp"

#include <sstream>
#include <fstream>

User::User(string uName, string pwd) {
	username = uName;
	password = pwd;
	debt = 0.0;
	derivedClassType = "user";
}

User::User(string uName, string pwd, double myDebt) {
	username = uName;
	password = pwd;
	debt = myDebt;
	derivedClassType = "user";
}


User::~User() {
	for(int i = 0; i < borrow_history.size(); i++) {
		delete borrow_history.at(i);
	}
}


void User::borrow_book(string bookName, BookCollection* listOfBooks) {
	Book* userBorrowedBook = nullptr;
	bool hasCheckedOutBefore = false;
	userBorrowedBook = listOfBooks -> search_book(bookName);

	if (userBorrowedBook == nullptr) {
		cout << "Book not found or already checked out" << endl;
	}

	else {
		curr_borrowed_books.push_back(userBorrowedBook);
		
		for (int i = 0; i < borrow_history.size(); i++) {
			if(userBorrowedBook->getTitle() == borrow_history.at(i)->getTitle()) {
				hasCheckedOutBefore = true;
			}
		}
	}

	if (hasCheckedOutBefore == false) {
		borrow_history.push_back(userBorrowedBook);
	}	
}

void User::return_book(string bookName) {
	return;

}

string User::get_account_debt() {
	stringstream ss;
	string doubleToDebt = "";

	ss >> debt;
	ss << doubleToDebt;

	return "$" + doubleToDebt;
}


void User::pay_debt(double payAmount) {
	if(payAmount != debt) {
		cout << "Error: Payment does not equal debt amount." << endl;
	}
	else {
		debt = 0;
	}
}


void User::display_curr_borrowed() {
	if (curr_borrowed_books.size() == 0) {
		cout << "You have no borrowed books" << endl;
		return;
	}

	for (int i = 0; i < curr_borrowed_books.size(); i++) {
		cout << i + 1 << "." << endl;
 		cout << "Title: " << curr_borrowed_books.at(i)->getTitle() << endl;
		cout << "Author: "<< curr_borrowed_books.at(i)->get_author() << endl;
	}
}

void User::display_past_borrowed() {
	
	if (borrow_history.size() == 0) {
		cout << "You have never borrowed books before" << endl;
		return;
	}	

	for (int i = 0; i < borrow_history.size(); i++) {
		cout << i + 1 << "." << endl;
		cout << "Title: " << borrow_history.at(i)->getTitle() << endl;
		cout << "Author: " << borrow_history.at(i)->get_author() << endl;
	}

}
vector<Book*> User::create_book_recommends() {
	vector<Book*>myBooks(0);
	return myBooks;
}


void User::save_user_books(ofstream& personStorage) {
	
	if (curr_borrowed_books.size() == 0) {
		personStorage << "None" << endl;
	}
	
	for(int i = 0; i < curr_borrowed_books.size(); i++) {
		if (i != curr_borrowed_books.size() - 1){
			personStorage << curr_borrowed_books.at(i)->getTitle() << ",";	
		}

		else {
			personStorage << curr_borrowed_books.at(i)->getTitle();
		}		
	}

	personStorage << endl;

	if (borrow_history.size() == 0) {
		personStorage << "None" << endl;
	}	
	for (int i = 0; i < borrow_history.size(); i++) {
		if(i != borrow_history.size() - 1) {
			personStorage << borrow_history.at(i)->getTitle() << ",";
		}

		else {
			personStorage << borrow_history.at(i)->getTitle(); 
		}
	}

	personStorage << endl;
	
	personStorage << debt;
}


void User::addToBorrowHistory(string bookName, BookCollection* listOfBooks) {
	Book* previouslyBorrowedBook = nullptr;
	previouslyBorrowedBook = listOfBooks->search_book(bookName);
	borrow_history.push_back(previouslyBorrowedBook);	
}



void User::doMenuOperations(BookCollection* bookC) {
	string userInput = "";
	
	while(userInput != "Q" && userInput != "q") {

		cout << "|--------------------|" << endl;
		cout << "Welcome to Your Library System" << endl;
		cout << "Please press one of the following buttons to continue" << endl << endl;

		cout << "1 - Borrow a book" << endl;
		cout << "2 - Return a book" << endl;
		cout << "3 - View your currently borrowed books" << endl;
		cout << "4 - View books you have checked out in the past" << endl;
		cout << "5 - Check account debt" << endl;
		cout << "6 - Pay debt" << endl;
		cout << "7 - View book reccomendations based off your borrow history!" << endl;
		cout << "8 - Show books in system" << endl;
		cout << "q or Q - To quit" << endl << endl;

		cout << "Choose an option: ";
		cin >> userInput;
		cout << endl;
		
		cout << "|--------------------|" << endl;

		if (userInput == "1") {
			string bookTitleToBorrow = "";

			cout << "Please enter the title of the book you would like to borrow: ";
			cin >> bookTitleToBorrow;
			cout << endl;
			
			borrow_book(bookTitleToBorrow, bookC);
						
		}

		else if (userInput == "2") {
			string bookTitleToReturn= "";
			
			cout << "Please enter the title of the book you would like to return: ";
			cin >> bookTitleToReturn;
			cout << endl;

			return_book(bookTitleToReturn);
		}

		else if (userInput == "3") {			
			cout << "Here is a list of your currently borrowed books:" << endl;
			display_curr_borrowed();
		}

		else if (userInput == "4") {
			cout << "Here is a list of the books you've checked out in the past" << endl;
			
			display_past_borrowed();			
		}

		else if (userInput == "5") {
			cout << "Here is your account debt!" << endl;
			cout << "Account debt: ";
			cout << get_account_debt() << endl;
		}

		else if (userInput == "6") {
			cout << "Enter amount you would like to pay: ";
			
			double debtPayment = 0.0;
			cin >> debtPayment;

			pay_debt(debtPayment);
		}

		else if (userInput == "7") {
			cout << "Here is a list of books based off of your borrow history: " << endl;
			
			vector<Book*>myPastBooks;		
			myPastBooks = create_book_recommends();

			for(int i = 0; i < myPastBooks.size(); i++) {
				cout << myPastBooks.at(i)->getTitle() << endl;
			}		
		}
		else if (userInput == "8") {
			display_books(bookC);
		}

		else if (userInput == "Q" || userInput == "q") {
			cout << "Bye! Have a swell day" << endl;

			return;
		}
	}
}

