#ifndef PERSON_HPP
#define PERSON_HPP

#include "book.hpp"
//#include "librarySystem.hpp"
#include "bookCollection.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {

protected: 
  string username;
  string password;
  string derivedClassType;
public:
  string getDerivedClassType();
  virtual ~Person();
  void display_books(BookCollection* bookC);
  bool doesUsrMatchPassword(string passedInUsername, string passedInPassword);
  string getUsername();
  string getPassword();
  virtual void doMenuOperations(BookCollection* bookC) = 0;
  virtual void save_user_books(ofstream& personStorage) = 0;
};


#endif
