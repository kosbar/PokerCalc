// Created by kosbar on 11/10/20.

#ifndef POKERCALC_CARD_H
#define POKERCALC_CARD_H

#include <cstdint>
#include <ostream>

#define CARD(X, Y) { _ ## X, #X, Y, #Y}
//CARD(2, s) = {_2, 2, s, s} // struct card

class Card {
private:
    enum suit {
        s = 2, h = 3, d = 5, c = 7
    };

    enum value {
        _2 = 2, _3 = 3, _4 = 5, _5 = 7, _6 = 11, _7 = 13,
        _8 = 17, _9 = 19, _T = 23, _J = 29, _Q = 31, _K = 37, _A = 41
    };

    uint_fast8_t value_of_card;
    const char *val; //для удобства вывода на печать дополнительные чары тут

    uint_fast8_t suit_of_card;
    const char *sui; //и тут

public:
    bool operator==(const Card &c);

    bool operator>(const Card &c);

    friend std::ostream& operator<<(std::ostream &os, const Card &crd);
};

#endif //POKERCALC_CARD_H
