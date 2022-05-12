#ifndef USERMENU_HPP
#define USERMENU_HPP

#include "menu.hpp"

class UserMenu : public Menu {  //implementation of one of the strategies
	public:
	   void doMenuOperations(Person* libUser, LibrarySystem* lib_sys) override;
};



#endif
