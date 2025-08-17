#include "../include/management.h"
#include <iostream>
#include <algorithm>

using namespace std;

Management::Management() : max_bid(-1) {
}

void Management::printAllBooks() const{
    std::cout << "当前所有书籍信息：" << std::endl;

    // for (const auto& pair : books) {
    //     pair.second.printBook();
    // }
    std::vector<int> keys;
    for (const auto& pair : books) {
        keys.push_back(pair.first);
    }
    std::sort(keys.begin(), keys.end());
    for (int key : keys) {
        books.at(key).printBook();
    }
}



void Management::storeBook(const Book& book) {
    max_bid++;
    books[max_bid] = book;
    books[max_bid].setBid(max_bid);
}

void Management::incBookStock(int bookId, int inc) {
    books[bookId].incStock(inc);
}

void Management::storeBooks(const std::vector<Book>& store_books) {
    for (const auto& book : store_books) {
        storeBook(book);
    }

}

void Management::removeBook(int bookId) {
    books.erase(bookId);
}

void Management::modifyBookInfo(Book book) {

}
