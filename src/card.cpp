#include "../include/card.h"
#include <iostream>

Card::Card(const std::string& card_owner)
    : cardId(-1), card_owner(card_owner) {
    // Initialize borrows if needed
    borrows = std::unordered_map<int, std::vector<Borrow>>();
}

int Card::getCardId() const {
    return cardId;
}

std::string Card::getCardOwner() const {
    return card_owner;
}

void Card::setCardId(int cardId) {
    this->cardId = cardId;
}

std::unordered_map<int, std::vector<Borrow>> Card::getBorrows() const {
    return borrows;
}

void Card::addBorrowRecord(int bookId, const Borrow& borrow) {
    borrows[bookId].push_back(borrow);
}

void Card::showCard() const {
    std::cout << "Card ID: " << cardId << ", Card Owner: " << card_owner << std::endl;
}

void Card::showCardDetails() const {
    std::cout << "-------------------Card ID: " << cardId << ", Card Owner: " << card_owner << "  --------------" << std::endl;
    std::cout << "Borrow Records: " << std::endl;
    for (const auto& pair : borrows) {
        for (const auto& borrow : pair.second) {
            borrow.showBorrow();
        }
    }
}
