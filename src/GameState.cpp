#include "GameState.hpp"

using namespace std;

void PlayerGameState::nextSet()
{
    board.clear();
    points = stood = 0;
}

namespace
{
    auto toPoints(Card card)
    {
        if (card >= P1)
            return i(card) - i(P1) + 1;
        else
            return -(i(card) - i(M1) + 1);
    }
}

void PlayerGameState::playCard(Card card)
{
    board.push_back(card);
    points += toPoints(card);
    if (points == 20 or board.size() == 9)
        stood = true;
}

void PlayerGameState::playCardFromDeck(int index, bool reverse)
{
    const auto card = deck[index];
    if (card <= PM6)
        playCard(Card(reverse ? card + M1 : card + P1));
    else
        playCard(card);
    deck.erase(cbegin(deck) + index);
}

int PlayerGameState::simCard(Card card) const
{
    return points + toPoints(card);
}
