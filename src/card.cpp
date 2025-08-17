#include "../include/card.h"


Card::Card(int cid, const std::string& card_owner)
    : cid(cid), card_owner(card_owner) {}

int Card::getCid() const {
    return cid;
}

std::string Card::getCardOwner() const {
    return card_owner;
}
