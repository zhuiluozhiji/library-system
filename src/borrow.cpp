#include "../include/borrow.h"
#include <iostream>

Borrow::Borrow(int bookId, int cardId, const std::chrono::system_clock::time_point& borrowTime)
    : bookId(bookId), cardId(cardId), borrowTime(borrowTime), returnTime(borrowTime) {}

int Borrow::getBookId() const { return bookId; }
int Borrow::getCardId() const { return cardId; }
std::chrono::system_clock::time_point Borrow::getBorrowTime() const { return borrowTime; }
std::chrono::system_clock::time_point Borrow::getReturnTime() const { return returnTime; }
void Borrow::setReturnTime(const std::chrono::system_clock::time_point& returnTime){
    this->returnTime = returnTime;
}




void Borrow::showBorrow() const {
    std::time_t borrowTimeT = std::chrono::system_clock::to_time_t(borrowTime);
    std::time_t returnTimeT = std::chrono::system_clock::to_time_t(returnTime);
    std::cout << "Book ID: " << bookId << ", Borrow Time: " << std::ctime(&borrowTimeT) << ", Return Time: " << std::ctime(&returnTimeT) << std::endl;
}
//rr