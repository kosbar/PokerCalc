#include <iostream>
#include <ostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <random>
#include <map>
#include "Card.h"

//Функция принта колоды
void pr(std::vector<Card> &deck) {
    std::cout << "deck.size(): " << deck.size() << std::endl;
    std::cout << "deck.capacity(): " << deck.capacity() << std::endl;
    std::cout << "vector: " << '\n';
    for (int i = 0; i < deck.size(); ++i) {
        //для разграничения колоды по мастям:
        if (i != 0 && deck[i].suit_of_card != deck[i - 1].suit_of_card) { std::cout << std::endl; } std::cout << " " << deck[i] << ' ';
    }
    std::cout << '\n';
}

//Функция вычета выданных карт из колоды, чтобы не продублировать их на доске.
void deck_minus_hand(std::vector<Card> &deck, std::vector<Card> &hand) {

    for (auto &c : hand) { deck.erase(std::remove(deck.begin(), deck.end(), c), deck.end()); }
    //pr(deck);
}

void oesd_multiplies(std::vector<uint64_t> &oesd, std::vector<Card> &deck) {
    oesd.clear();
    //we need one suit only:
    unsigned long s = deck.size() / 4;
    uint64_t oesd_in_deck;

    //Начиная с двойки (нам нужны двухсторонние дро) идём до короля
    //и считаем произведение value_of_cardue по 4 карты в масти:
    for (int i = 0; i < s - 3; ++i) {
        oesd_in_deck = deck[i].value_of_card * deck[i + 1].value_of_card * deck[i + 2].value_of_card *
                       deck[i + 3].value_of_card;
        oesd.push_back(oesd_in_deck);
    }
}

void straight_multiplies(std::vector<uint64_t> &straights, std::vector<Card> &deck) {
    straights.clear();
    //we need one suit only:
    unsigned long s = deck.size() / 4 + 1; //размер масти для цикла
    uint64_t multuplies;

//    Начиная с туза (А1345) идём до T (TJQKA)
//    и считаем произведение value_of_cardue по 5 карт в масти:
    for (int i = 0; i < s; ++i) {
        multuplies = deck[(i + s) % s].value_of_card * deck[(i + s + 1) % s].value_of_card *
                     deck[(i + s + 2) % s].value_of_card * deck[(i + s + 3) % s].value_of_card *
                     deck[(i + s + 4) % s].value_of_card;
        //std::cout << multuplies << std::endl;
        straights.push_back(multuplies);
    }
}

//Выбираем те OESD в которых есть наши сданные карты:
void only_hand_oesd(std::vector<uint64_t> &oesd,
                    std::vector<Card> &hand,
                    std::vector<uint64_t> &oesd_minus) {
    for (auto &num : oesd) {
        if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
            oesd_minus.push_back(num);
        }
    }
}

//Выбираем те стриты, в которых участвуют наши карты:
void only_hand_straights(std::vector<uint64_t> &strights,
                         std::vector<Card> &hand,
                         std::vector<uint64_t> &strights_minus) {
    for (auto &num : strights) {
        if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
            strights_minus.push_back(num);
        }
    }
}

//комбинации карт как произведения простых чисел (основная теорема арифметики):
long multiply_value_of_cardue(std::vector<Card> &slice) {
    uint64_t value_of_cardue = 1;

    for (auto &i : slice) { value_of_cardue *= i.value_of_card; }

    return value_of_cardue;
}

//тоже самое с маcтями:
long multiply_suits(std::vector<Card> &slice) {
    uint64_t suits = 1;

    for (auto &i : slice) { suits *= i.suit_of_card; }

    std::cout << suits;

    return suits;
}

int main() {
    std::vector<Card> deck52 = {
            "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As",
            "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah",
            "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad",
            "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac"
    };

    std::vector<Card> deck36 = {
            "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As",
            "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah",
            "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad",
            "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac",
    };

    std::vector<Card> hand = {"Td", "Jc"};

    /// вектор со всеми возможными OESD в колоде.
    std::vector<uint64_t> oesd;
    oesd_multiplies(oesd, deck52); /// заполнили его

    /// отфилтровали OESD, оставив т.е., в которых есть сданные на руки карты
    std::vector<uint64_t> oesd_with_hand;
    only_hand_oesd(oesd, hand, oesd_with_hand);

    /// вектор со всеми возможными стритами в колоде.
    std::vector<uint64_t> strights;
    straight_multiplies(strights, deck52);

    /// отфилтровали стриты, оставив те, в которых есть сданные на руки карты
    std::vector<uint64_t> strights_with_hand;
    only_hand_straights(strights, hand, strights_with_hand);

    std::vector<Card> flop; ///вектор с первыми тремя картами стола.

    deck_minus_hand(deck52, hand); ///раздали карты.

    ///генерация флопа:
    std::sample(deck52.begin(),
                deck52.end(),
                std::back_inserter(flop),
                3,
                std::mt19937{std::random_device{ }() } );
    pr(flop);

    pr(deck52);

    return 0;
}
