#ifndef MENU_HPP
#define MENU_HPP

#include "person.hpp"
#include "user.hpp"
#include "librarySystem.hpp"
#include "book.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu {  //strategy class

	public:
	   virtual void doMenuOperations(Person* libPerson, LibrarySystem* lib_system) = 0;
};




#endif
