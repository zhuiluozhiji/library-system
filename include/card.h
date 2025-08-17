#pragma once

#include <string>

class Card {
public:
    Card(int cid, const std::string& card_owner);

    int getCid() const;
    std::string getCardOwner() const;

private:
    int cid;
    std::string card_owner;
};
