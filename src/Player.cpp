#include "Player.hpp"

#include "Random.hpp"

using namespace std;

namespace
{
    Deck deck1() { return {P3, P4, P4, P5, P5, M3, M3, M4, M5, M5}; }
    Deck deck2() { return {P2, P3, P3, P4, M2, M2, M3, M4, PM1, PM6}; }
    Deck deck3() { return {PM1, PM1, PM2, PM2, PM2, PM2, PM3, PM3, PM4, PM4}; }
    Deck randomizedDeck()
    {
        Deck deck(10);
        generate(begin(deck), end(deck), []() { return randomCardUsable(); });
        return deck;
    }
    Deck bigDeck() { return {M6, M6, M6, M6, M6, M6, M6, M6, M6, M6}; }
    Deck defaultDeck() { return {P1, P2, P3, P4, P5, M1, M2, M3, M4, M5}; }

    [[maybe_unused]] Deck randomDeck()
    {
        switch (randomNumber(1, 5))
        {
            case 1: return deck1();
            case 2: return deck2();
            case 3: return deck3();
            case 4: return randomizedDeck();
            case 5: return bigDeck();
            default: return defaultDeck();
        }
    }
}

Player::Player() : deck(deck3()) {}

const Deck& Player::provideDeck()
{
    return deck;
}
