#include "book.h"
#include "card.h"

#include <vector>
#include <unordered_map>
#include <ctime>
#include <chrono>

class Management {
public:
    Management();

    void showAllBooks() const;
    void showAllBorrows() const;

    void storeBook(const Book& book);
    void incBookStock(int bookId, int inc);
    void storeBooks(const std::vector<Book>& books);
    void removeBook(int bookId);
    void modifyBookInfo(int bookId, Book book);
    bool registerCard(const Card& card);
    bool removeCard(int cardId);
    void showCards() const;
    bool borrowBook(int bookId, int cardId);
    bool returnBook(int bookId, int cardId);
    bool showBorrowHistory(int cardId) const;





private:
    std::unordered_map<int, Book> books; // 用书号作为key
    int max_bid;
    int max_cid;
    std::unordered_map<int, Card> cards;
};
