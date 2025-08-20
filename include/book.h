#pragma once

#include <string>

class Book {
public:
    Book() = default;
    Book(const std::string& title, const std::string& author, int stock);

    int getBookId() const;
    void setBookId(int bid);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getStock() const;
    void incStock(int inc);
    void showBook() const;

private:
    int bookId;   
    std::string title;
    std::string author;
    int stock;

};
