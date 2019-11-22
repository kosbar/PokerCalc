#include <iostream>
#include <ostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <random>
#include <map>

#define CARD(X, Y) { _ ## X, #X, Y, #Y}
//CARD(2, s) = {_2, 2, s, s} // struct card

enum suit {
    s = 2, h = 3, d = 5, c = 7
};
enum value {
    _2 = 2, _3 = 3, _4 = 5, _5 = 7, _6 = 11, _7 = 13,
    _8 = 17, _9 = 19, _T = 23, _J = 29, _Q = 31, _K = 37, _A = 41
};

//карта
struct card {

    uint_fast8_t value_of_card;
    const char *val; //для удобства вывода на печать дополнительные чары тут
    uint_fast8_t suit_of_card;
    const char *sui; //и тут

    bool operator==(const card &c) {
        return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
    }

    bool operator>(const card &c) {
        return (c.suit_of_card == suit_of_card) && (c.value_of_card == value_of_card);
    }
};

std::ostream &operator<<(std::ostream &os, const card &crd) {
    os << crd.val << crd.sui;
    return os;
}

//Функция принта колоды

void pr(std::vector<card> &deck) {

    std::cout << "deck.size(): " << deck.size() << std::endl;
    std::cout << "deck.capacity(): " << deck.capacity() << std::endl;
    std::cout << "vector: " << '\n';
    for (int i = 0; i < deck.size(); ++i) {

        //для разграничения колоды по мастям:
        if (i != 0 && deck[i].suit_of_card != deck[i - 1].suit_of_card) { std::cout << std::endl; }
        std::cout << " " << deck[i] << ' ';
    }
    std::cout << '\n';
}

//Функция вычета выданных карт из колоды, чтобы не продублировать их на доске.
void deck_minus_hand(std::vector<card> &deck, std::vector<card> &hand) {

    for (auto &c : hand) { deck.erase(std::remove(deck.begin(), deck.end(), c), deck.end()); }
    //pr(deck);
}

void oesd_multiplies(std::vector<uint64_t> &oesd, std::vector<card> &deck) {

    oesd.clear();
    //we need one suit only:
    unsigned long s = deck.size() / 4;
    uint64_t oesd_in_deck;

    //Начиная с двойки (нам нужны двухсторонние дро) идём до короля
    //и считаем произведение value по 4 карты в масти:

    for (int i = 0; i < s - 3; ++i) {
        oesd_in_deck = deck[i].value_of_card * deck[i + 1].value_of_card * deck[i + 2].value_of_card *
                       deck[i + 3].value_of_card;
        oesd.push_back(oesd_in_deck);
    }
}

void straight_multiplies(std::vector<uint64_t> &straights, std::vector<card> &deck) {
    straights.clear();
    //we need one suit only:
    unsigned long s = deck.size() / 4 + 1; //размер масти для цикла
    uint64_t multuplies;

//    Начиная с туза (А1345) идём до T (TJQKA)
//    и считаем произведение value по 5 карт в масти:

    for (int i = 0; i < s; ++i) {
        multuplies = deck[(i + s) % s].value_of_card * deck[(i + s + 1) % s].value_of_card *
                     deck[(i + s + 2) % s].value_of_card * deck[(i + s + 3) % s].value_of_card *
                     deck[(i + s + 4) % s].value_of_card;
        //std::cout << multuplies << std::endl;
        straights.push_back(multuplies);
    }
}

//Выбираем те OESD в которых есть наши сданные карты:
void only_hand_oesd(std::vector<uint64_t> &oesd, std::vector<card> &hand, std::vector<uint64_t> &oesd_minus) {
    for (auto &num : oesd) {
        if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
            oesd_minus.push_back(num);
        }
    }
}

//Выбираем те стриты, в которых участвуют наши карты:
void only_hand_straights(std::vector<uint64_t> &strights, std::vector<card> &hand,
                         std::vector<uint64_t> &strights_minus) {
    for (auto &num : strights) {
        if (!(num % hand[0].value_of_card) | !(num % hand[1].value_of_card)) {
            strights_minus.push_back(num);
        }
    }
}


//комбинации карт как произведения простых чисел (основная теорема арифметики):
long multiply_value(std::vector<card> &slice) {
    uint64_t value = 1;

    for (auto &i : slice) { value *= i.value_of_card; }

    return value;
}

//тоже самое с маcтями:
long multiply_suits(std::vector<card> &slice) {
    uint64_t suits = 1;

    for (auto &i : slice) { suits *= i.suit_of_card; }

    std::cout << suits;

    return suits;
}

int main() {
    std::vector<card> deck52 = {CARD(2, s), CARD(3, s), CARD(4, s), CARD(5, s), CARD(6, s), CARD(7, s), CARD(8, s),
                                CARD(9, s), CARD(T, s), CARD(J, s), CARD(Q, s), CARD(K, s), CARD(A, s),
                                CARD(2, h), CARD(3, h), CARD(4, h), CARD(5, h), CARD(6, h), CARD(7, h), CARD(8, h),
                                CARD(9, h), CARD(T, h), CARD(J, h), CARD(Q, h), CARD(K, h), CARD(A, h),
                                CARD(2, d), CARD(3, d), CARD(4, d), CARD(5, d), CARD(6, d), CARD(7, d), CARD(8, d),
                                CARD(9, d), CARD(T, d), CARD(J, d), CARD(Q, d), CARD(K, d), CARD(A, d),
                                CARD(2, c), CARD(3, c), CARD(4, c), CARD(5, c), CARD(6, c), CARD(7, c), CARD(8, c),
                                CARD(9, c), CARD(T, c), CARD(J, c), CARD(Q, c), CARD(K, c), CARD(A, c)};

    std::vector<card> deck36 = {CARD(6, s), CARD(7, s), CARD(8, s), CARD(9, s), CARD(T, s), CARD(J, s), CARD(Q, s),
                                CARD(K, s), CARD(A, s),
                                CARD(6, h), CARD(7, h), CARD(8, h), CARD(9, h), CARD(T, h), CARD(J, h), CARD(Q, h),
                                CARD(K, h), CARD(A, h),
                                CARD(6, d), CARD(7, d), CARD(8, d), CARD(9, d), CARD(T, d), CARD(J, d), CARD(Q, d),
                                CARD(K, d), CARD(A, d),
                                CARD(6, c), CARD(7, c), CARD(8, c), CARD(9, c), CARD(T, c), CARD(J, c), CARD(Q, c),
                                CARD(K, c), CARD(A, c)};

    std::vector<card> hand = {CARD(T, d), CARD(J, c)};


    std::vector<uint64_t> oesd;    /// вектор со всеми возможными OESD в колоде.
    oesd_multiplies(oesd, deck52); /// заполнили его

    std::vector<uint64_t> oesd_with_hand; ///отфилтровали OESD, оставив т е, в которых есть сданные на руки карты
    only_hand_oesd(oesd, hand, oesd_with_hand);

    std::vector<uint64_t> strights; /// вектор со всеми возможными стритами в колоде.
    straight_multiplies(strights, deck52);

    std::vector<uint64_t> strights_with_hand; ///отфилтровали стриты, оставив те, в которых есть сданные на руки карты
    only_hand_straights(strights, hand, strights_with_hand);

    std::vector<card> flop; ///вектор с первыми тремя картами стола.

    deck_minus_hand(deck52, hand); ///раздали карты.

    ///генерация флопа:
    std::sample(deck52.begin(), deck52.end(), std::back_inserter(flop), 3, std::mt19937{std::random_device{}()});
    pr(flop);

    pr(deck52);

    return 0;
}

#undef CARD