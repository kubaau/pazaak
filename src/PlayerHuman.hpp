#pragma once

#include "Player.hpp"

class PlayerHuman : public Player
{
public:
    Move move(const PlayerGameState& you, const PlayerGameState& opponent, bool card_played) override;
};
