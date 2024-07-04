#include "Random.hpp"

using namespace std;

int randomNumber(int min, int max)
{
    return uniform_int_distribution<>{min, max}(defaultRandomEngine());
}

Card randomCard1to10()
{
    static uniform_int_distribution<> d{P1, P10};
    return Card(d(defaultRandomEngine()));
}

Card randomCardUsable()
{
    static uniform_int_distribution<> d{M1, P6};
    return Card(d(defaultRandomEngine()));
}
