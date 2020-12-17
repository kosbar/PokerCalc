// Created by kosbar on 12/11/20.

#include "Slice.h"

Slice::Slice(std::initializer_list<Card>&& cards) : cards(cards) {
    for(auto c : cards) {
        trips.insert(c.value_of_card * c.value_of_card * c.value_of_card);
    }
}

void Slice::_multiplies(int size = 2) {
    
}

std::set<unsigned long long> Slice::getTrips(Deck& deck) {
    return trips;
}

std::set<unsigned long long> Slice::getFulls() {
//    for(auto f : deck.getFulls()) {
//
//    }
//    return fulls;
}