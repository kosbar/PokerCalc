cmake_minimum_required(VERSION 3.10)
project(PokerCalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(PokerCalc main.cpp Deck.cpp Deck.h Card.cpp Card.h Poker.cpp Poker.h)