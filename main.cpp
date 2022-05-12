#include "person.hpp"
#include "admin.hpp"
#include "user.hpp"
#include "book.hpp"
#include "librarySystem.hpp"
#include "bookCollection.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	LibrarySystem* libSystem =  new LibrarySystem();
	
	libSystem->run();

	return 0;
}
