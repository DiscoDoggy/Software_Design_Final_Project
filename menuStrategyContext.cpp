#include "menuStrategyContext.hpp"

MenuStrategyContext::MenuStrategyContext(){
	newMenu = nullptr;
}

void MenuStrategyContext::setMenuStrategy(Menu* passedInMenu) {
	newMenu = passedInMenu;
}

void MenuStrategyContext::executeStrategy(Person* passedInPerson, LibrarySystem* libSys) {
	newMenu->doMenuOperations(passedInPerson, libSys);
}

