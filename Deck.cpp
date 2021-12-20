// Created by kosbar on 21.11.2019.

#include <iostream>
#include <cmath>
#include "Deck.h"

#include <algorithm>

Deck::Deck() : cards {"As", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks",
                      "Ah", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh",
                      "Ad", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd",
                      "Ac", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc" }

{ _fullHouses(); _oesd(); _straights(straights); };

// Multiply of cards of all straights in cards
void Deck::_straights(std::set<unsigned long long> &multiplies, int straightSize) {
    multiplies.clear();

    // we need one suit only:
    unsigned long suitSize = cards.size() / 4; // размер масти для цикла
    unsigned long long multiply_straights;

    // Начиная с туза (А1345) идём до T (TJQKA)
    // и считаем произведение value_of_cardue по straightSize карт в масти:
    for (int i = 0; i <= (suitSize - straightSize + 1); ++i) {
        int innerStraightSize = 0;
        multiply_straights = 1;

        while (innerStraightSize < straightSize) {
           multiply_straights *= cards[(i + suitSize + innerStraightSize) % suitSize].value_of_card;
            ++innerStraightSize;
       }
       multiplies.insert(multiply_straights);
    }
}

void Deck::_oesd() {
    _straights(oesd, 4);
}

// Multiply of cards of all full houses (FH) in cards
void Deck::_fullHouses() {
   _trips();
   for (auto t : trips) {
       for (auto c : cards) {
           if (round(pow(t, 1.0/3.0)) != c.value_of_card) {
               fulls.insert(t * c.value_of_card * c.value_of_card);
           }
       }
   }
};

// all FH with our hand cards
void Deck::_trips() {
    for (auto c : cards) {
        trips.insert(c.value_of_card * c.value_of_card * c.value_of_card);
    }
};

//Deck& Deck::operator-(Slice& slice) {
//    for (auto &c : slice.cards) {
//        cards.erase(std::remove(cards.begin(), cards.end(), c), cards.end());
//    }
//    return *this;
//}

std::set<unsigned long long> Deck::getOESD() {
    return oesd;
}

std::set<unsigned long long> Deck::getStraights() {
    return straights;
}

std::set<unsigned long long> Deck::getFulls() {
    return fulls;
}

void Deck::pr() {
    std::cout << "cards.size(): " << cards.size() << std::endl;
    std::cout << "cards.capacity(): " << cards.capacity() << std::endl;
    std::cout << "vector: " << '\n';

    for (int i = 0; i < cards.size(); ++i) {
        //для разграничения колоды по мастям:
        if (i != 0 && cards[i].suit_of_card != cards[i - 1].suit_of_card) {
            std::cout << std::endl; } std::cout << " " << cards[i] << ' ';
    }
    std::cout << '\n';
}