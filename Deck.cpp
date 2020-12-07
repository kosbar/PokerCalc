// Created by kosbar on 21.11.2019.

#include <iostream>
#include "Deck.h"

Deck::Deck() : cards {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As",
                      "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah",
                      "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad",
                      "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"}
{};

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
};

//Multiply of cards of all OESD in cards, each multiply is unique (Fundamental theorem of arithmetic).
void Deck::_oesd() {
    oesd.clear();
    // we need one suit only:
    // TODO: подумать над выносом мастей в отдельную переменную...
    // TODO: ...и созданием конструктора с любым количеством карт и мастей
    unsigned long s = cards.size() / 4;
    unsigned long long multiply_oesd;

    // Начиная с двойки (нам нужны двухсторонние дро) идём до короля
    // и считаем произведение value_of_cards по 4 карты в масти:
    for (int i = 0; i < s - 3; ++i) {
        multiply_oesd = cards[i].value_of_card * cards[i + 1].value_of_card * cards[i + 2].value_of_card *
                        cards[i + 3].value_of_card;
        oesd.insert(multiply_oesd);
    }
};

// Multiply of cards of all straights in cards
void Deck::_straights() {
    straights.clear();
    //we need one suit only:
    unsigned long suitSize = cards.size() / 4 + 1; //размер масти для цикла
    unsigned long long multiply_straights;

//    Начиная с туза (А1345) идём до T (TJQKA)
//    и считаем произведение value_of_cardue по 5 карт в масти:
    for (int i = 0; i < suitSize; ++i) {
        multiply_straights = cards[(i + suitSize) % suitSize].value_of_card * cards[(i + suitSize + 1) % suitSize].value_of_card *
                             cards[(i + suitSize + 2) % suitSize].value_of_card * cards[(i + suitSize + 3) % suitSize].value_of_card *
                             cards[(i + suitSize + 4) % suitSize].value_of_card;
        //std::cout << multuplies << std::endl;
        straights.insert(multiply_straights);
    }
};

//Multiply of cards of all full houses (FH) in cards
void Deck::_fullHouses() {
   for (auto t : trips) {
       for (auto c : cards) {
           if (t/3 != c.value_of_card) {
               fulls.insert(t * c.value_of_card * c.value_of_card);
           }
       }
   }
};

// all FH with our hand cards
void Deck::_trips() {
    for (auto c : cards) {
        trips.insert(c.value_of_card*3);
    }
};

//all OESD with our hand cards
// void Deck::only_hand_oesd() {};

//all Strights with our hand cards
// void Deck::only_hand_straights() {};