#ifndef MENUSTRATEGYCONTEXT_HPP
#define MENUSTRATEGYCONTEXT_HPP

#include "person.hpp"
#include "user.hpp"
#include "admin.hpp"
#include "librarySystem.hpp"
//#include "menu.hpp"
//#include "userMenu.hpp"
//#include "adminMenu.hpp"

class Menu;
class UserMenu;
class AdminMenu;

class MenuStrategyContext {
	private:
	   Menu* newMenu;

	public:
	   MenuStrategyContext();
	   void setMenuStrategy(Menu* passedInMenu);
	   void executeStrategy(Person* passedInPerson, LibrarySystem* libSys);


};


#endif
