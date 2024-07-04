#include <iomanip>
#include <sstream>

#include "GameState.hpp"
#include "Move.hpp"

using namespace std;

ostream& operator<<(ostream& os, Card card)
{
    switch (card)
    {
        case P1: return os << " +1";
        case P2: return os << " +2";
        case P3: return os << " +3";
        case P4: return os << " +4";
        case P5: return os << " +5";
        case P6: return os << " +6";
        case P7: return os << " +7";
        case P8: return os << " +8";
        case P9: return os << " +9";
        case P10: return os << "+10";
        case M1: return os << " -1";
        case M2: return os << " -2";
        case M3: return os << " -3";
        case M4: return os << " -4";
        case M5: return os << " -5";
        case M6: return os << " -6";
        case PM1: return os << "+-1";
        case PM2: return os << "+-2";
        case PM3: return os << "+-3";
        case PM4: return os << "+-4";
        case PM5: return os << "+-5";
        case PM6: return os << "+-6";
        default: return os << "???";
    }
}

ostream& operator<<(ostream& os, const Deck& deck)
{
    ostringstream oss;
    for (auto card : deck)
        oss << card << " ";
    return os << oss.str();
}

ostream& operator<<(ostream& os, Move move)
{
    switch (move)
    {
        case CARD1_FACE: return os << "CARD1_FACE";
        case CARD2_FACE: return os << "CARD2_FACE";
        case CARD3_FACE: return os << "CARD3_FACE";
        case CARD4_FACE: return os << "CARD4_FACE";
        case CARD1_REVERSE: return os << "CARD1_REVERSE";
        case CARD2_REVERSE: return os << "CARD2_REVERSE";
        case CARD3_REVERSE: return os << "CARD3_REVERSE";
        case CARD4_REVERSE: return os << "CARD4_REVERSE";
        case END_TURN: return os << "END_TURN";
        case STAND: return os << "STAND";
        case NEXT_GAME: return os << "NEXT_GAME";
        case QUIT: return os << "QUIT";
        default: return os << "???";
    }
}

ostream& operator<<(ostream& os, const PlayerGameState& state)
{
    os << left << setw(20) << state.deck << setw(40) << state.board << state.points;
    if (state.stood)
        os << "\t\tSTOOD";
    return os << endl;
}
