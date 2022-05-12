#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "person.hpp"
#include "bookCollection.hpp"

using namespace std;

class User : public Person {
	private:
	   vector<Book*> curr_borrowed_books;
	   vector<Book*> borrow_history;
	   double debt;


	public:
	   User(string uName, string pwd);
	   User(string uName, string pwd, double myDebt);	   
	   ~User();
	   void borrow_book(string bookName, BookCollection* listOfBooks);
	   void return_book(string bookName);
	  
	   string get_account_debt();
	   void pay_debt(double payAmount);

	   void display_curr_borrowed();
	   void display_past_borrowed();

	   vector<Book*>create_book_recommends();

	   void doMenuOperations(BookCollection* bookC) override;

	   void save_user_books(ofstream& personStorage);
	   void addToBorrowHistory(string bookName, BookCollection* listOfBooks);
};



#endif
