#pragma once

#include <memory>

#include "Player.hpp"

class Game
{
    struct PlayerData;

public:
    using PlayerPtr = std::unique_ptr<Player>;
    using Players = std::pair<PlayerPtr, PlayerPtr>;

    Game(Players, int games = -1);
    void run();

private:
    void startGame();
    void finishGame();
    void startSet();
    void finishSet();

    bool gameInProgress() const;
    bool setInProgress() const;
    bool move();
    void printState() const;
    const PlayerData* determineWinner() const;

    struct PlayerData
    {
        PlayerPtr player;
        PlayerGameState state;
    } p1, p2, *current, *other;
    int games;
};
