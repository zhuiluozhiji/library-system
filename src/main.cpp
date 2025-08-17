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

    m.printAllBooks();

    m.incBookStock(0, 3);
    m.removeBook(1);
    m.storeBooks(books);
    m.printAllBooks();

    return 0;
}


