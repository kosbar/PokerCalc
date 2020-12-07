// Created by kosbar on 21.11.2019.

#ifndef POKERCALC_DECK_H
#define POKERCALC_DECK_H

#include <set>
#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
    std::set<unsigned long long> oesd;
    std::set<unsigned long long> straights;
    std::set<unsigned long long> trips;
    std::set<unsigned long long> fulls;

public:
    Deck();

    // Print of deck
    void pr();

    // Get our hand from deck
    void operator-(Deck& slice);

    // Multiply of cards of all OESD in deck, each multiply is unique (Fundamental theorem of arithmetic).
    void _oesd();

    // Multiply of cards of all straights in deck
    void _straights();

    // Multiply of cards of all full houses (FH) in deck
    void _fullHouses();

    // all FH with our hand cards
    void _trips();

    // all OESD with our hand cards
//    void only_hand_oesd();

    // all Strights with our hand cards
//    void only_hand_straights();

};

#endif //POKERCALC_DECK_H
