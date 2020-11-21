// Created by kosbar on 11/10/20.

#include "Card.h"
#include <string>
#include <iostream>

Card::Card(const char* c) : str(c) {
    _setter(str);
}

Card::Card(std::string s) : str(s) {
    _setter(str);
}

void Card::_setter(std::string string) {
    switch (string[0]) {
        case '2' : this->value_of_card = 2; break;
        case '3' : this->value_of_card = 3; break;
        case '4' : this->value_of_card = 5; break;
        case '5' : this->value_of_card = 7; break;
        case '6' : this->value_of_card = 11; break;
        case '7' : this->value_of_card = 13; break;
        case '8' : this->value_of_card = 17; break;
        case '9' : this->value_of_card = 19; break;
        case 'T' : this->value_of_card = 23; break;
        case 'J' : this->value_of_card = 29; break;
        case 'Q' : this->value_of_card = 31; break;
        case 'K' : this->value_of_card = 37; break;
        case 'A' : this->value_of_card = 41; break;
        default : std::cout << "Error uncorrected input"; break;
    }

    switch (string[1]) {
        case 's' : this->suit_of_card = 2; break;
        case 'h' : this->suit_of_card = 3; break;
        case 'd' : this->suit_of_card = 5; break;
        case 'c' : this->suit_of_card = 7; break;
        default : std::cout << "Error uncorrected input"; break;
    }
}

Card& Card::operator=(const Card &c) {
    this->suit_of_card = c.suit_of_card;
    this->value_of_card = c.value_of_card;
    this->str = c.str;

    return *this;
}

bool Card::operator==(const Card &c) {
    return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
}

bool Card::operator>(const Card &c) {
    return (c.value_of_card > value_of_card);
}

bool Card::operator<(const Card &c) {
    return (c.value_of_card < value_of_card);
}

std::ostream& operator<<(std::ostream &os, const Card &crd) {
    os << crd.str;

    return os;
}

std::istream &operator>>(std::istream &is, Card &c) {
    std::string s;
    is >> s;

    Card tmp(s);
    c = tmp;

    return is;
}