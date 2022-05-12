#ifndef PERSONFACTORY_HPP
#define PERSONFACTORY_HPP

#include "person.hpp"
#include "user.hpp"
#include "admin.hpp"
#include "bookCollection.hpp"

class PersonFactory {

	public:
		vector<Person*>Parse(BookCollection* passedInCollection);
		









};



#endif
