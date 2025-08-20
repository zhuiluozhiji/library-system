#pragma once

#include "borrow.h"
#include <string>
#include <unordered_map>
#include <vector>


class Card {
public:
    Card() = default;
    Card(const std::string& card_owner);

    int getCardId() const;
    std::string getCardOwner() const;
    void setCardId(int cardId);
    std::unordered_map<int, std::vector<Borrow>> getBorrows() const;
    void addBorrowRecord(int bookId, const Borrow& borrow);
    void showCard() const;
    void showCardDetails() const;

private:
    int cardId;
    std::string card_owner;
    std::unordered_map<int, std::vector<Borrow>> borrows; // 书籍ID -> 借阅记录

};
