#include "Card.h"

#ifndef POKER_H
#define POKER_H
//namespace poker {
    void deck_minus_hand(std::vector<Card>& deck, std::vector<Card>& hand);
    void oesd_multiplies(std::vector<uint64_t>& oesd, std::vector<Card>& deck);
    void straight_multiplies(std::vector<uint64_t>& straights, std::vector<Card>& deck, int straightSize);
    void only_hand_oesd(std::vector<uint64_t>& oesd, std::vector<Card>& hand, std::vector<uint64_t>& oesd_minus);
    void only_hand_straights(std::vector<uint64_t>& strights, std::vector<Card>& hand, std::vector<uint64_t>& strights_minus);
    long multiply_value_of_cards(std::vector<Card>& slice);
    long multiply_suits(std::vector<Card>& slice);
    void generateSlice(std::vector<Card>& deck, std::vector<Card>& desk, int size);
    void getCombinations(std::vector<unsigned long long> parent, std::vector< unsigned long long>::iterator startPosition, int sizeCombination, std::set<unsigned long long> combinations);
//}
#endif