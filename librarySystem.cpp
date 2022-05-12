#include "librarySystem.hpp"
#include <fstream>
using namespace std;

LibrarySystem::LibrarySystem() {
	current_time = 0;
}

void LibrarySystem::run() {
	string userInput = "";
	Person* loggedInPerson = nullptr;
	
	load_system();

	while (userInput != "1" && userInput != "2") {
		print_login_and_reg_menu();
		
		cout << endl;
		cin >> userInput;
		cout << endl;

		if (userInput != "1" && userInput != "2") {
			cout << "Invalid option, please enter a valid option" << endl << endl;
		}
	}	

	if (userInput == "1") {
		loggedInPerson = login();
	}
	else if (userInput == "2") {
		loggedInPerson = register_person();
	}

	cout << "Welcome " << loggedInPerson->getUsername() << "!" << endl;
		
	if(loggedInPerson->getDerivedClassType() == "user") {
		loggedInPerson->doMenuOperations(bookC);	
	}

	else if (loggedInPerson->getDerivedClassType() == "admin") {
		loggedInPerson->doMenuOperations(bookC);
	}

	save_system();


}

LibrarySystem::~LibrarySystem() {
	for(int i = 0; i < libraryPeople.size(); i++) {
		delete libraryPeople.at(i);
	}
	delete bookC;

}

void LibrarySystem::print_login_and_reg_menu() {
	cout << "|--------------------|" << endl;
	cout << "Welcome to the Library System" << endl;
	cout << "Please choose to Register or Login" << endl << endl;

	cout << "1 - Login" << endl;
	cout << "2 - Register" << endl;
}

Person* LibrarySystem::login() {
	Person* loggedInPerson = nullptr;
	while(loggedInPerson == nullptr) {
		string username = "";
		string password = "";
		loggedInPerson = nullptr;

		cout << endl;
		cout << "Please Enter Your Username and Password" << endl << endl;

		cout << "Username: ";
		cin >> username;

		cout << endl;

		cout << "Password: ";
		cin >> password;

		for(int i = 0; i < libraryPeople.size(); i++) {
			if (libraryPeople.at(i)->doesUsrMatchPassword(username, password)) {
				loggedInPerson = libraryPeople.at(i);
			}		
		} 
	
		if (loggedInPerson == nullptr) {
			cout << "Invalid username or password" << endl << endl;
		}
		else {
			return loggedInPerson;
		}
	}

}

Person* LibrarySystem::register_person() {
	bool doesExistAlready = false;
	string newUsername = "";
	string newPassword = "";
	
	while (doesExistAlready == false) {
		cout << "Please enter a username and password to register" << endl << endl;
		
		cout << "Username: ";
		cin >> newUsername;

		cout << endl;
		
		cout << "Password: ";
		cin >> newPassword;

		for (int i = 0; i <  libraryPeople.size(); i++) {
			if(libraryPeople.at(i)->getUsername() == newUsername) {
				cout << "Invalid username, already taken" << endl;
				doesExistAlready = true;
			}
		}

		if (doesExistAlready == false) {
		  
		  string s = "";
		  while ((s != "1") && (s !=  "2")) {
		      cout << "Press (1) to register as an Admin and (2) to register as a User:";
		      cin >> s;
		      cout << endl;
		      if (s == "1") {
			Person* newPerson = new Admin(newUsername, newPassword);
			libraryPeople.push_back(newPerson);
			return newPerson;
		      }
		      if (s == "2") { 
			Person* newPerson = new User(newUsername, newPassword);
			libraryPeople.push_back(newPerson);
			return newPerson;
			}
		      }
		}		
	}		
}


void LibrarySystem::save_system() {
	bookC->saveBooksToFile();
	savePersons();
	
}

void LibrarySystem::load_system() {
  //loadBooks();
	//PersonFactory* loadPeople = new PersonFactory();

	//	libraryPeople = loadPeople->Parse(bookC);
}
    
void LibrarySystem::sortBooks() {
  char choice;
  TitleAZ a;
  TitleZA b;
  AuthorAZ c;
  AuthorZA d;
  while (choice != ('Q' || 'q')) {
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

void LibrarySystem::savePersons() {
	ofstream outfile;
	
	outfile.open("allLibraryPeople.txt");

	if (!outfile.is_open()) {
		cout << "failure to file to store people" << endl;
		exit(-1);
	}

	for (int i = 0; i < libraryPeople.size(); i++) {
		outfile << libraryPeople.at(i)->getDerivedClassType() << endl;
		outfile << libraryPeople.at(i)->getUsername() << endl;
		outfile << libraryPeople.at(i)->getPassword() << endl;

		if (libraryPeople.at(i)->getDerivedClassType() == "user") {
			libraryPeople.at(i)->save_user_books(outfile);
		}

		outfile << endl;
	}

	outfile.close();

}

void LibrarySystem::loadBooks() {
	ifstream inFS;
	string title = "";
	string author = "";

	inFS.open("libraryBooks.txt");
	if(!inFS.is_open()) {
		cout << "File to load library books from not found" << endl;
		exit(-1);
	}

	while (inFS) {
		getline(inFS, title);
		getline(inFS, author);

		if (!inFS) {
			break;
		}

		Book* loadedInBook = new Book(title, author);
		bookC->add_book(loadedInBook);			
	}
	

}





