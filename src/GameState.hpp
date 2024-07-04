#pragma once

#include "Card.hpp"

struct PlayerGameState
{
    Deck deck;
    Deck board;
    int points;
    bool stood;
    int sets_won;
    int games_won = 0;

    void nextSet();
    void playCard(Card);
    int simCard(Card) const;
    void playCardFromDeck(int index, bool reverse = false);
};

std::ostream& operator<<(std::ostream&, const PlayerGameState&);
