#pragma once

#include "GameState.hpp"
#include "Move.hpp"

class Player
{
public:
    Player();
    virtual ~Player() {}

    virtual Move move(const PlayerGameState& you, const PlayerGameState& opponent, bool card_played) = 0;

    const Deck& provideDeck();

private:
    Deck deck;
};
