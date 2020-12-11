// Created by kosbar on 11/10/20.

#ifndef POKERCALC_CARD_H
#define POKERCALC_CARD_H

#include <cstdint>
#include <ostream>

class Card {

public:
    std::string str = ""; //строка для ввода и вывода значения карты
    unsigned long long value_of_card = 0;
    int suit_of_card = 0;

    Card(char const* c);

    Card(std::string s);

    Card& operator=(const Card& c);

    bool operator==(const Card &c);

    bool operator>(const Card &c);

    bool operator<(const Card &c);

    void _setter(std::string);

    friend std::ostream& operator<<(std::ostream &os, const Card &crd);

    friend std::istream& operator>>(std::istream &is, Card& c);
};

#endif //POKERCALC_CARD_H
