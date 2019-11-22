//
// Created by kosbar on 21.11.2019.
//

#include <iostream>
#include "Deck.h"

struct Deck::card {

    uint_fast8_t value_of_card;
    uint_fast8_t suit_of_card;

    //для удобства вывода на печать дополнительные чары тут
    const char *val;
    const char *sui;

    bool operator==(const card &c) {
        return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
    }

    bool operator>(const card &c) {
        return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
    }

    std::ostream &operator<<(std::ostream &os, const card &crd) {
        os << crd.val << crd.sui;
        return os;
    }
};

//Necessary give number of cards in deck (52, 36 ...)
Deck::Deck(int num) : numberOfCards(num) {};

void Deck::pr() {
    std::cout << "Deck size: " << deck.size() << std::endl;
    std::cout << "Deck: " << '\n';

    for (int i = 0; i < deck.size(); ++i) {

        //для разграничения колоды по мастям:
        if (i != 0 && deck[i].suit_of_card != deck[i - 1].suit_of_card) { std::cout << std::endl; }
        std::cout << " " << deck[i] << ' ';
    }

    std::cout << '\n';
};

//Get our hand from deck
void Deck::deck_minus_hand(std::array<card, N>  ) {

};

//Multiply of cards of all OESD in deck, each multiply is unique (Fundamental theorem of arithmetic).
void Deck::oesd_multiplies() {};

//Multiply of cards of all straights in deck
void Deck::straight_multiplies() {};

//Multiply of cards of all full houses (FH) in deck
//void FH_multiplies();

//all FH with our hand cards
//void only_hand_FH();

//all OESD with our hand cards
void Deck::only_hand_oesd() {};

//all Strights with our hand cards
void Deck::only_hand_straights() {};

