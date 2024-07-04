#pragma once

#include <ostream>
#include <vector>

enum Card
{
    PM1,
    PM2,
    PM3,
    PM4,
    PM5,
    PM6,
    M1,
    M2,
    M3,
    M4,
    M5,
    M6,
    P1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7,
    P8,
    P9,
    P10,
};
std::ostream& operator<<(std::ostream&, Card);

inline auto i(Card card)
{
    return static_cast<int>(card);
}

using Deck = std::vector<Card>;
std::ostream& operator<<(std::ostream&, const Deck&);
