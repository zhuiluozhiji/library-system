#include "../include/management.h"
#include "../include/utils.h"
#include <iostream>
#include <algorithm>

using namespace std;

Management::Management() : max_bid(-1) , max_cid(-1){

}

void Management::showAllBooks() const{
    std::cout << "当前所有book信息：" << std::endl;

    // for (const auto& pair : books) {
    //     pair.second.printBook();
    // }
    std::vector<int> keys;
    for (const auto& pair : books) {
        keys.push_back(pair.first);
    }
    std::sort(keys.begin(), keys.end());
    for (int key : keys) {
        books.at(key).showBook();
    }
}

void Management::showAllBorrows() const {
    std::cout << ">>>>>>>>>>>>>>当前所有借书记录<<<<<<<<<<<<<<<<<<" << std::endl;
    for (const auto& pair : cards) {
        pair.second.showCardDetails();
    }
}

void Management::storeBook(const Book& book) {
    max_bid++;
    books[max_bid] = book;
    books[max_bid].setBookId(max_bid);
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

void Management::modifyBookInfo(int bookId, Book book) {
    if (books.find(bookId) != books.end() && books[bookId].getStock() == book.getStock()) {
        book.setBookId(bookId);
        books[bookId] = book;
        //cout << "modify!!" <<endl;
    } else {
        std::cerr << "Book with ID " << bookId << " does not exist or stock does not match." << std::endl;
    }
}

bool Management::registerCard(const Card& card) {
    for (const auto& existingCard : cards) {
        if (card.getCardOwner() == existingCard.second.getCardOwner()) {
            std::cerr << "Card owner already exists." << std::endl;
            return false;
        }
    }
    max_cid++;
    cards[max_cid] = card;
    cards[max_cid].setCardId(max_cid);

    return true;
}



bool Management::removeCard(int cardId) {
    if (cards.find(cardId) != cards.end()) {
        for(const auto& pair : cards[cardId].getBorrows()) {
            for (const auto& borrow : pair.second) {
                if (borrow.getReturnTime() == borrow.getBorrowTime()) {
                    std::cerr << "Card has active borrow records, cannot remove." << std::endl;
                    return false;
                }
            }
        }

        cards.erase(cardId);
        return true;
    }
    return false;
}

void Management::showCards() const {
    std::cout << "当前所有card信息" << std::endl;
    vector<int> keys;
    for(const auto& pair : cards) {
        keys.push_back(pair.first);
    }
    sort(keys.begin(), keys.end());

    for(const auto& key : keys) {
        cards.at(key).showCard();
    }
}


bool Management::borrowBook(int bid, int cid){
    if (books.find(bid) != books.end() && books[bid].getStock() > 0) {
        vector <Borrow> borrows = (cards[cid].getBorrows())[bid];
        for (const auto& borrow : borrows) {
            // Process each borrow record as needed
            if(borrow.getReturnTime() == borrow.getBorrowTime()) {
                std::cout << "Book is already borrowed by this card." << std::endl;
                return false;
            }
        }
        books[bid].incStock(-1);
        auto now = std::chrono::system_clock::now();
        cards[cid].addBorrowRecord(bid, Borrow(cid, bid, now));
        return true;
    }
    return false;
}

bool Management::returnBook(int bookId, int cardId) {
    if (books.find(bookId) != books.end() && cards.find(cardId) != cards.end()) {
        vector<Borrow>& borrows = cards[cardId].getBorrows()[bookId];
        cout << "borrows.size() - 1 = " << borrows.size() - 1 << endl; 
        if(borrows[borrows.size() - 1].getReturnTime() != borrows[borrows.size() - 1].getBorrowTime()) {
            std::time_t borrowTimeT = std::chrono::system_clock::to_time_t(borrows[borrows.size() - 1].getBorrowTime());
            std::time_t returnTimeT = std::chrono::system_clock::to_time_t(borrows[borrows.size() - 1].getReturnTime());
            std::cout << "ReturnTime = " << std::ctime(&returnTimeT) << " borrowTime = " << std::ctime(&borrowTimeT) << std::endl;
            std::cerr << "Book has already been returned by this card." << std::endl;
            return false;
        }

        books[bookId].incStock(1);
        auto now = std::chrono::system_clock::now();
        borrows.back().setReturnTime(now);
        return true;
    }
    std::cerr << "Book ID " << bookId << " or Card ID " << cardId << " not found." << std::endl;
    return false;
}

bool Management::showBorrowHistory(int cardId) const{
    if (cards.find(cardId) != cards.end()) {
        cards.at(cardId).showCardDetails();
        return true;
    }
    std::cerr << "Card ID " << cardId << " not found." << std::endl;
    return false;
}

