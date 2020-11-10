// Created by kosbar on 11/10/20.

#include "Card.h"
bool Card::operator==(const Card &c) {
    return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
}

bool Card::operator>(const Card &c) {
    return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
}

std::ostream& operator<<(std::ostream &os, const Card &crd) {
    os << crd.val << crd.sui;
    return os;
}