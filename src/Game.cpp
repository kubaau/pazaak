#include "Game.hpp"

#include <algorithm>

#include "Logging.hpp"
#include "Random.hpp"

using namespace std;

Game::Game(Players ps, int games) : games(games)
{
    p1.player = std::move(ps.first);
    p2.player = std::move(ps.second);
}

void Game::run()
{
    const auto total_games_for_percentage = games / 100.0f;
    while (games)
    {
        startGame();
        while (gameInProgress())
        {
            startSet();
            while (setInProgress())
            {
                current->state.playCard(randomCard1to10());
                if (not move())
                    return;
            }
            finishSet();
        }
        finishGame();
    }
    cerr << "Summary: " << p1.state.games_won << " (" << p1.state.games_won / total_games_for_percentage << "%) vs "
         << p2.state.games_won << " (" << p2.state.games_won / total_games_for_percentage << "%)" << endl;
}

static auto chooseGameDeck(Deck deck)
{
    cout << deck << endl;
    Deck ret(4);
    sample(cbegin(deck), cend(deck), begin(ret), ret.size(), defaultRandomEngine());
    return ret;
}

void Game::startGame()
{
    p1.state.deck = chooseGameDeck(p1.player->provideDeck());
    p2.state.deck = chooseGameDeck(p2.player->provideDeck());
    p1.state.sets_won = p2.state.sets_won = 0;
}

void Game::finishGame()
{
    auto& winner = p1.state.sets_won == 3 ? p1 : p2;
    ++winner.state.games_won;

    cout << "WINNER: Player " << (&winner == &p1 ? "1" : "2") << "!!!\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Wins: " << p1.state.games_won << " vs " << p2.state.games_won << endl;
    cout << "--------------------------------------------------------------------\n";

    if (games != -1)
        --games;
}

void Game::startSet()
{
    p1.state.nextSet();
    p2.state.nextSet();
    current = &p1;
    other = &p2;
}

void Game::finishSet()
{
    auto winner = const_cast<PlayerData*>(determineWinner());
    if (not winner)
        cout << "\nSet tied!\n";
    else
    {
        ++winner->state.sets_won;
        cout << "\nPlayer " << (winner == &p1 ? "1" : "2") << " wins!\n";
    }
    cout << "Sets won: " << p1.state.sets_won << " vs " << p2.state.sets_won << endl;
    cout << "--------------------------------------------------------------------\n";
}

bool Game::gameInProgress() const
{
    return p1.state.sets_won < 3 and p2.state.sets_won < 3;
}

bool Game::setInProgress() const
{
    return not(p1.state.stood and p2.state.stood) and p1.state.points <= 20 and p2.state.points <= 20;
}

bool Game::move()
{
    Move move = CARD1_FACE;
    bool card_played = false;
    while (move != END_TURN)
    {
        if (card_played and current->state.points > 20)
            current->state.stood = true;

        printState();

        if (current->state.stood)
            break;

        move = current->player->move(current->state, other->state, card_played);
        cout << "Move: " << move << endl;

        if (move == STAND)
            current->state.stood = true;
        else if (move == QUIT)
            return false;
        else if (move == NEXT_GAME)
        {
            current->state.sets_won = 2;
            other->state.points = 21;
            break;
        }
        else if (move != Move::END_TURN)
        {
            if (move < CARD1_REVERSE)
                current->state.playCardFromDeck(static_cast<int>(move));
            else
                current->state.playCardFromDeck(static_cast<int>(move - CARD1_REVERSE), true);
            card_played = true;
        }
    };

    if (not other->state.stood)
        swap(current, other);

    return true;
}

void Game::printState() const
{
    cout << endl << p1.state << p2.state;
    cout << "Player moving: " << (current == &p1 ? "1" : "2") << endl;
}

const Game::PlayerData* Game::determineWinner() const
{
    if (p1.state.points > 20)
        return &p2;
    if (p2.state.points > 20)
        return &p1;
    if (p1.state.points == p2.state.points)
        return {};
    return p1.state.points > p2.state.points ? &p1 : &p2;
}
