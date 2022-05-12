#include "userMenu.hpp"


void UserMenu::doMenuOperations(Person* libPerson, LibrarySystem* lib_system) {
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
			
			libPerson->borrow_book(bookTitleToBorrow);
						
		}

		else if (userInput == "2") {
			string bookTitleToReturn= "";
			
			cout << "Please enter the title of the book you would like to return: ";
			cin >> bookTitleToReturn;
			cout << endl;

			libPerson->return_book(bookTitleToReturn);
		}

		else if (userInput == "3") {			
			cout << "Here is a list of your currently borrowed books:" << endl;
			libPerson->display_curr_borrowed();
		}

		else if (userInput == "4") {
			cout << "Here is a list of the books you've checked out in the past" << endl;
			
			libPerson->display_past_borrowed();			
		}

		else if (userInput == "5") {
			cout << "Here is your account debt!" << endl;
			cout << "Account debt: ";
			cout << libUser->get_account_debt() << endl;
		}

		else if (userInput == "6") {
			cout << "Enter amount you would like to pay: ";
			
			double debtPayment = 0.0;
			cin >> debtPayment;

			libPerson->pay_debt(debtPayment);
		}

		else if (userInput == "7") {
			cout << "Here is a list of books based off of your borrow history: " << endl;
			
			vector<Book*>myPastBooks;		
			myPastBooks = libPerson->create_book_recommends();

			for(int i = 0; i < myPastBooks.size(); i++) {
				cout << myPastBooks.at(i)->getTitle() << endl;
			}		
		}

		else if (userInput == "Q" || userInput == "q") {
			cout << "Bye! Have a swell day" << endl;

			return;
		}
	}

}
