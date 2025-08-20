#include "../include/book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int stock)
    : bookId(-1), title(title), author(author), stock(stock) {}

int Book::getBookId() const {
    return bookId;
}

void Book::setBookId(int bookId) {
    this->bookId = bookId;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getStock() const {
    return stock;
}

void Book::incStock(int inc) {
    stock += inc;
}

void Book::showBook() const {
    std::cout << "Book ID: " << bookId << ", Title: " << title << ", Author: " << author << ", Stock: " << stock << std::endl;
}