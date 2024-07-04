#include <chrono>

#include "Game.hpp"
#include "Logging.hpp"
#include "PlayerAI.hpp"
#include "PlayerHuman.hpp"

using namespace std;
using namespace chrono;

namespace
{
    Game::PlayerPtr getPlayer(char c = 0)
    {
        if (c == 'a')
            return make_unique<PlayerAI>();
        else
            return make_unique<PlayerHuman>();
    }

    Game::Players getPlayers(int argc, char** argv)
    {
        Game::Players players;
        players.first = argc > 1 ? getPlayer(argv[1][0]) : getPlayer();
        players.second = argc > 2 ? getPlayer(argv[2][0]) : getPlayer();
        return players;
    }
}

int main(int argc, char* argv[])
try
{
    const auto start = high_resolution_clock::now();

    int argv1;
    if (argc > 1 and (argv1 = atoi(argv[1])))
        Game{{make_unique<PlayerAI>(), make_unique<PlayerAI>()}, argv1}.run();
    else
        Game{getPlayers(argc, argv), 3}.run();

    duration<double> elapsed_seconds = high_resolution_clock::now() - start;
    cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    return EXIT_SUCCESS;
}
catch (exception& ex)
{
    cout << ex.what() << endl;
    return EXIT_FAILURE;
}
