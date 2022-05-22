#include <iostream>
#include <ostream>
#include <set>
#include <algorithm>
#include <random>

#include "Card.h"
#include "Deck.h"
#include "Poker.h"


int main() {
    std::vector<Card> hand = {"Td", "Jc"};

    std::vector<Card> deck52 = { 
                    "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "Ts", "Js", "Qs", "Ks", "As", 
                    "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "Th", "Jh", "Qh", "Kh", "Ah",
                    "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "Td", "Jd", "Qd", "Kd", "Ad",
                    "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "Tc", "Jc", "Qc", "Kc", "Ac", };

    // вектор со всеми возможными OESD в колоде.
    std::vector<uint64_t> oesd;
    oesd_multiplies(oesd, deck52); /// заполнили его
    
    /// отфилтровали OESD, оставив те, в которых есть сданные на руки карты
    std::vector<uint64_t> oesd_with_hand;
    only_hand_oesd(oesd, hand, oesd_with_hand);

    /// вектор со всеми возможными стритами в колоде.
    std::vector<uint64_t> strights;
    straight_multiplies(strights, deck52, 5);

    /// отфилтровали стриты, оставив те, в которых есть сданные на руки карты
    std::vector<uint64_t> strights_with_hand;
    only_hand_straights(strights, hand, strights_with_hand);

    std::vector<Card> flop; ///вектор с первыми тремя картами стола.

    deck_minus_hand(deck52, hand); ///раздали карты.

    int two_pair = 0;
    int one_pair = 0;
    int oesd_hand = 0;
    int iteration = 10000;

    // for (int i = 0; i < iteration; ++i) {
    //     generateSlice(deck52, flop, 3);
    //     long mult_flop = multiply_value_of_cards(flop);

    //     if (!(mult_flop % (hand[0].value_of_card * hand[1].value_of_card))) {
    //            ++two_pair;

    //     } else if (!(mult_flop % hand[0].value_of_card) || !(mult_flop % hand[1].value_of_card)) {
    //           ++one_pair;

    //     } else {
    //            for (auto c : oesd_with_hand) {
    //                if (!(mult_flop * hand[0].value_of_card * hand[1].value_of_card % c)) {
    //                    ++oesd_hand;
    //                 break;
    //             }
    //         }
    //     }
    // }

//    std::cout << "Количество пар: " << 100*(float)one_pair/(float)iteration << "%" << std::endl;
//    std::cout << "Количество двух пар: " << 100*(float)two_pair/(float)iteration << "%" << std::endl;
//    std::cout << "Количество OESD: " << 100*(float)oesd_hand/(float)iteration << "%" << std::endl;

   Deck* deck = new Deck();
   deck->pr();

    return 0;
}
