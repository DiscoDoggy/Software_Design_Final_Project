#ifndef LIBRARYSYSTEM_HPP
#define LIBRARYSYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"
#include "user.hpp"
#include "admin.hpp"
#include "book.hpp"
#include "personFactory.hpp"
#include "bookCollection.hpp"
#include "sort.hpp"

class LibrarySystem {
	private:
           BookCollection* bookC = new BookCollection();
	   vector<Person*> libraryPeople;
	   int current_time;
	   void print_login_and_reg_menu();
	public:
	   LibrarySystem();
	   ~LibrarySystem();
	   Person* register_person();

	   void save_system();
	   void savePersons();
	   void load_system();
	   void loadBooks();
	   void sortBooks();
	   Person* login();
	   void run();

	   

};


#endif
