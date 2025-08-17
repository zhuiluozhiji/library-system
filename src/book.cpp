#include "../include/book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int stock)
    : bid(-1), title(title), author(author), stock(stock) {}

int Book::getBid() const {
    return bid;
}

void Book::setBid(int bid) {
    this->bid = bid;
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

void Book::printBook() const {
    std::cout << "Book ID: " << bid << ", Title: " << title << ", Author: " << author << ", Stock: " << stock << std::endl;
}