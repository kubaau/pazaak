#include "PlayerHuman.hpp"

#include "Logging.hpp"

using namespace std;

namespace
{
    void printAvailableMoves(const Deck& deck, bool card_played)
    {
        if (not card_played)
            for (auto i = 0u; i < deck.size(); ++i)
            {
                cout << "[" << i + 1 << "] " << deck[i] << endl;
            }
        cout << "[e] end turn\n[s] stand\n";
    }

    void invalidMove(string s, string explanation) { cout << "Invalid move - " << explanation << ": " << s << endl; }

    auto getValidMove(const Deck& deck, bool card_played)
    {
        string s;
        while (true)
        {
            cin >> s;
            const auto c = s[0];
            const auto choice = c - '1';

            if (s.length() > 1)
                invalidMove(s, "too long");

            else if (c == 'e')
                return END_TURN;
            else if (c == 's')
                return STAND;
            else if (c == 'n')
                return NEXT_GAME;
            else if (c == 'q')
                return QUIT;

            else if (c < '1' or c > '4')
                invalidMove(s, "unrecognized");
            else if (choice >= static_cast<char>(deck.size()))
                invalidMove(s, "not enough cards");
            else if (card_played)
                invalidMove(s, "card already played");
            else if (deck[choice] <= PM6)
                while (true)
                {
                    cout << "[1]" << Card(deck[choice] + P1) << " [2]" << Card(deck[choice] + M1) << endl;
                    cin >> s;
                    if (s == "1")
                        return Move(choice);
                    else if (s == "2")
                        return Move(choice + CARD1_REVERSE);
                }
            else
                return Move(choice);
        }
    }
}

Move PlayerHuman::move(const PlayerGameState& you, const PlayerGameState&, bool card_played)
{
    printAvailableMoves(you.deck, card_played);
    return getValidMove(you.deck, card_played);
}
