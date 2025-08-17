#pragma once

#include <string>

class Book {
public:
    Book() = default;
    Book(const std::string& title, const std::string& author, int stock);

    int getBid() const;
    void setBid(int bid);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getStock() const;
    void incStock(int inc);
    void printBook() const;

private:
    int bid;   
    std::string title;
    std::string author;
    int stock;

};
