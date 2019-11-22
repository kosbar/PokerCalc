//
// Created by kosbar on 21.11.2019.
//

#ifndef POKERCALC_DECK_H
#define POKERCALC_DECK_H


#include <array>

class Deck {

private:

    //struct aboit play card:
    struct card;
    int numberOfCards;
    //and deck of cards (52 or less by numberOfCards):
    std::array<card, numberOfCards> deck;

public:

    Deck(int num);

    //Print of deck
    void pr();

    //Get our hand from deck
    void deck_minus_hand();

    //Multiply of cards of all OESD in deck, each multiply is unique (Fundamental theorem of arithmetic).
    void oesd_multiplies();

    //Multiply of cards of all straights in deck
    void straight_multiplies();

    //Multiply of cards of all full houses (FH) in deck
    void FH_multiplies();

    //all FH with our hand cards
    void only_hand_FH();

    //all OESD with our hand cards
    void only_hand_oesd();

    //all Strights with our hand cards
    void only_hand_straights();

};


#endif //POKERCALC_DECK_H
