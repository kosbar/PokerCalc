// Created by kosbar on 11/10/20.

#include "Card.h"
#include <string>
#include <iostream>

Card::Card(char const* c) {
    Card((std::string) c);
}

Card::Card(std::string s) : _str(s) {
    if (s.length() == 2) {
        switch (s[0]) {
            case '2' : _value_of_card = 2; break;
            case '3' : _value_of_card = 3; break;
            case '4' : _value_of_card = 5; break;
            case '5' : _value_of_card = 7; break;
            case '6' : _value_of_card = 11; break;
            case '7' : _value_of_card = 13; break;
            case '8' : _value_of_card = 17; break;
            case '9' : _value_of_card = 19; break;
            case 'T' : _value_of_card = 23; break;
            case 'J' : _value_of_card = 29; break;
            case 'Q' : _value_of_card = 31; break;
            case 'K' : _value_of_card = 37; break;
            case 'A' : _value_of_card = 41; break;
            default :
                std::cout << "Error uncorrected input";
        }
        switch (s[1]) {
            case 's' : _suit_of_card = 2; break;
            case 'h' : _suit_of_card = 3; break;
            case 'd' : _suit_of_card = 5; break;
            case 'c' : _suit_of_card = 7; break;
            default :
                std::cout << "Error uncorrected input";
        }
    }
}

Card& Card::operator=(const Card &c) {
    this->_suit_of_card = c._suit_of_card;
    this->_value_of_card = c._value_of_card;
    this->_str = c._str;

    return *this;
}

bool Card::operator==(const Card &c) {
    return (c._suit_of_card == _suit_of_card) && (c._value_of_card == _value_of_card);
}

bool Card::operator>(const Card &c) {
    return (c._value_of_card > _value_of_card);
}

bool Card::operator<(const Card &c) {
    return (c._value_of_card < _value_of_card);
}

std::ostream& operator<<(std::ostream &os, const Card &crd) {
    os << crd._str;

    return os;
}

std::istream &operator>>(std::istream &is, Card &c) {
    std::string s;
    is >> s;

    Card tmp(s);
    c = tmp;

    return is;
}
