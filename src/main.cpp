#include <iostream>
#include "../include/book.h"
#include "../include/management.h"

using namespace std;

int main(){
    Management m;
    Book a("t1", "a1", 5);
    Book b("t2", "a2", 3);
    Book c("t3", "a3", 2);
    Book d("t4", "a3", 1);
    Book e("t5", "a3", 0);
    Book f("t6", "a3", 0);

    vector<Book> books = {e, f};

    m.storeBook(a);
    m.storeBook(b);
    m.storeBook(c);
    m.storeBook(d);

    m.showAllBooks();

    m.incBookStock(0, 3);
    m.removeBook(1);
    m.storeBooks(books);
    m.modifyBookInfo(0, Book("t1", "a11", 8));

    m.showAllBooks();

    Card c1("Alice");
    Card c2("Bob");
    Card c3("Charlie");
    Card c4("David");

    m.registerCard(c1);
    m.registerCard(c2);
    m.registerCard(c3);
    m.registerCard(c4);

    m.removeCard(0);
    m.showCards();
    m.borrowBook(0, 1);
    m.borrowBook(0, 2);
    m.borrowBook(0, 3);

    m.showAllBooks();
    m.showAllBorrows();
    
    
    m.returnBook(0, 1);


    return 0;
}


