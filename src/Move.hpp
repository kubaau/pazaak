#pragma once

#include <ostream>

enum Move
{
    CARD1_FACE,
    CARD2_FACE,
    CARD3_FACE,
    CARD4_FACE,
    CARD1_REVERSE,
    CARD2_REVERSE,
    CARD3_REVERSE,
    CARD4_REVERSE,
    END_TURN,
    STAND,
    NEXT_GAME,
    QUIT
};
std::ostream& operator<<(std::ostream&, Move);
