#include "book.h"
#include "card.h"

#include <vector>
#include <unordered_map>

class Management {
public:
    Management();

    void printAllBooks() const;

    void storeBook(const Book& book);
    void incBookStock(int bookId, int inc);
    void storeBooks(const std::vector<Book>& books);
    void removeBook(int bookId);
    void modifyBookInfo(Book book);




private:
    std::unordered_map<int, Book> books; // 用书号作为key
    int max_bid;
    std::vector<Card> cards;
};
