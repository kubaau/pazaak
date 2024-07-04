#include "PlayerAI.hpp"

namespace
{
    auto good(int you, int opponent) { return you == 20 or (you == 19 and opponent != 20); }
}

Move PlayerAI::move(const PlayerGameState& you, const PlayerGameState& opponent, bool card_played)
{
    if (opponent.stood)
    {
        if (you.points <= 20 and you.points > opponent.points)
            return STAND;
    }

    if (good(you.points, opponent.points))
        return STAND;

    if (card_played or you.points <= 13)
        return END_TURN;

    if (you.deck.empty() and you.points >= 16 and opponent.points <= 16)
        return STAND;

    for (auto i = 0u; i < you.deck.size(); ++i)
    {
        const auto card = you.deck[i];
        if (card <= PM6)
        {
            if (good(you.simCard(Card(card + P1)), opponent.points))
                return Move(CARD1_FACE + i);

            if (good(you.simCard(Card(card + M1)), opponent.points))
                return Move(CARD1_REVERSE + i);
        }
        else if (good(you.simCard(card), opponent.points))
            return Move(CARD1_FACE + i);
    }

    return END_TURN;
}
