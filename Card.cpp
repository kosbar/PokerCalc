// Created by kosbar on 11/10/20.

#include "Card.h"
bool Card::operator==(const Card &c) {
    return (c._suit_of_card == _suit_of_card) && (c._value_of_card == _value_of_card);
}

bool Card::operator>(const Card &c) {
    return (c._suit_of_card == _suit_of_card) && (c._value_of_card == _value_of_card);
}

std::ostream& operator<<(std::ostream &os, const Card &crd) {
    os << crd._val << crd._sui;
    return os;
}