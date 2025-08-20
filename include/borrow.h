#pragma once
#include <string>
#include <chrono>
#include <optional>
#include <ctime>

class Borrow{
public:

    Borrow(int bookId, int cardId, const std::chrono::system_clock::time_point& borrowTime);

    int getBookId() const;
    int getCardId() const;
    std::chrono::system_clock::time_point getBorrowTime() const;
    std::chrono::system_clock::time_point getReturnTime() const;
    void setReturnTime(const std::chrono::system_clock::time_point& returnTime);
    void showBorrow() const;

private:
    int bookId;
    int cardId;
    std::chrono::system_clock::time_point borrowTime;
    std::chrono::system_clock::time_point returnTime;


};