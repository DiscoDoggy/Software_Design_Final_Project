#include "sort.hpp"

void TitleAZ::sort(vector<Book*>& books) {
  std::sort(books.begin(), books.end(), [](Book* a, Book* b) {
      return a->get_name() < b->get_name();
    });
}

void TitleZA::sort(vector<Book*>& books) {
  std::sort(books.begin(), books.end(), [](Book* a, Book* b) {
      return a->get_name() > b->get_name();
    });
}

void AuthorAZ::sort(vector<Book*>& books) {
  std::sort(books.begin(), books.end(), [](Book* a, Book* b) {
      return a->get_author() < b->get_author();
    });
}

void AuthorZA::sort(vector<Book*>& books) {
  std::sort(books.begin(), books.end(), [](Book* a, Book* b) {
      return a->get_author() > b->get_author();
    });
}
