// Created by kosbar on 12/11/20.

#ifndef POKERCALC_SLICE_H
#define POKERCALC_SLICE_H

#include <set>
#include "Deck.h"

class Slice {
private:
    std::set<unsigned long long> multiplies;
    std::set<unsigned long long> oesd;
    std::set<unsigned long long> straights;
    std::set<unsigned long long> trips;
    std::set<unsigned long long> fulls;

    void _multiplies(int);

public:
    std::vector<Card> cards;

    Slice(std::initializer_list<Card>&&);

    // std::set<unsigned long long> getOESD(Deck&);
    // std::set<unsigned long long> getStraights(Deck&);
    std::set<unsigned long long> getTrips(Deck& deck);
    std::set<unsigned long long> getFulls();
    // std::set<unsigned long long> getMultiplies(int handSize);
};


#endif //POKERCALC_SLICE_H
