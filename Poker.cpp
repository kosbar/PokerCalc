#include <iostream>
#include <ostream>
#include <set>
#include <algorithm>
#include <random>

#include "Poker.h"
#include "Card.h"

//namespace poker {
        // Функция вычета выданных карт из колоды, чтобы не продублировать их на доске.
    void deck_minus_hand(std::vector<Card>& deck, std::vector<Card>& hand) {
        for (auto &c : hand) { deck.erase(std::remove(deck.begin(), deck.end(), c), deck.end()); }
        //pr(deck);
    }

    void oesd_multiplies(std::vector<uint64_t>& oesd, std::vector<Card>& deck) {
        oesd.clear();
        // нам достаточно одной масти:
        unsigned long s = deck.size() / 4;
        uint64_t oesd_in_deck;

        // Начиная с двойки (нам нужны двухсторонние дро) идём до короля
        // и считаем произведение value_of_cardue по 4 карты в масти:
        for (int i = 0; i < s - 3; ++i) {
            oesd_in_deck = deck[i].value_of_card * deck[i + 1].value_of_card * deck[i + 2].value_of_card *
                        deck[i + 3].value_of_card;
            oesd.push_back(oesd_in_deck);
        }
    }

    void straight_multiplies(std::vector<uint64_t>& straights, std::vector<Card>& deck, int straightSize) {
        straights.clear();
        //we need one suit only:
        unsigned long s = deck.size() / 4;
        std::cout << "size: " << s << std::endl;
        uint64_t multuplies = 1;

    //    Начиная с туза (А1345) идём до T (TJQKA)
    //    и считаем произведение value_of_cardue по 5 карт в масти:
        for (int i = 0; i < (s - (straightSize - 2)); ++i) {
            int innerStraightSize = straightSize - 1;
            multuplies = 1;

            while (innerStraightSize >= 0) {
                std::cout << "inner: " << innerStraightSize << std::endl;
                std::cout << i << ": " << deck[(i + s + innerStraightSize) % s].value_of_card << std::endl;

                multuplies = multuplies * deck[(i + s + innerStraightSize) % s].value_of_card;
                --innerStraightSize;

                std::cout << "multiplies: " << multuplies << std::endl;
            }

            std::cout << "----------------------------------------" << std::endl;
        //  multuplies = deck[(i + s) % s].value_of_card * deck[(i + s + 1) % s].value_of_card *
        //              deck[(i + s + 2) % s].value_of_card * deck[(i + s + 3) % s].value_of_card *
            //             deck[(i + s + 4) % s].value_of_card;
            //std::cout << multuplies << std::endl;
            straights.push_back(multuplies);
        }
    }

    // Выбираем те OESD в которых есть наши сданные карты:
    void only_hand_oesd(std::vector<uint64_t>& oesd,
                        std::vector<Card>& hand,
                        std::vector<uint64_t>& oesd_minus) {
        for (auto &num : oesd) {
            if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
                oesd_minus.push_back(num);
            }
        }
    }

    // Выбираем те стриты, в которых участвуют наши карты:
    void only_hand_straights(std::vector<uint64_t>& strights,
                            std::vector<Card>& hand,
                            std::vector<uint64_t>& strights_minus) {
        for (auto &num : strights) {
            if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
                strights_minus.push_back(num);
            }
        }
    }

    // комбинации карт как произведения простых чисел (основная теорема арифметики):
    long multiply_value_of_cards(std::vector<Card>& slice) {
        uint64_t value_of_cardue = 1;

        for (auto &i : slice) { value_of_cardue *= i.value_of_card; }

        return value_of_cardue;
    }

    // тоже самое с маcтями:
    long multiply_suits(std::vector<Card>& slice) {
        uint64_t suits = 1;

        for (auto &i : slice) { suits *= i.suit_of_card; }

        std::cout << suits;

        return suits;
    }

    void generateSlice(std::vector<Card>& deck, std::vector<Card>& desk, int size) {
        desk.clear();

        std::sample(deck.begin(),
                    deck.end(),
                    std::back_inserter(desk),
                    size,
                    std::mt19937{std::random_device{}()});
    }


    void getCombinations(std::vector<unsigned long long> parent,
                            std::vector< unsigned long long>::iterator startPosition,
                            int sizeCombination,
                            std::set<unsigned long long> combinations)
    {
        for(int i = *startPosition; i < parent.size(); ++i) {
            
        }
    }

//}