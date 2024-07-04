#pragma once

#include <random>

#include "Card.hpp"

int randomNumber(int min, int max);
Card randomCard1to10();
Card randomCardUsable();

inline auto& defaultRandomEngine()
{
    using namespace std;
    thread_local mt19937 dre{random_device{}()};
    return dre;
}
