#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "book.hpp"

class Sort {
public:
  //static bool comparator(Book* first, Book* second);
  virtual void sort(vector<Book*>& books) = 0;
};



class TitleAZ : public Sort {
public: 
  //bool comparator(Book* first, Book* second);
  virtual void sort(vector<Book*>& books);
};

class TitleZA : public Sort {
public:
  //bool comparator(Book* first, Book* second);
  virtual void sort(vector<Book*>& books);
};

class AuthorAZ : public Sort {
public:
  //bool comparator(Book* first, Book* second);
  virtual void sort(vector<Book*>& books);
};

class AuthorZA : public Sort {
public:
  //bool comparator(Book* first, Book* second);
  virtual void sort(vector<Book*>& books);
};

#endif
