#pragma once

#include <iostream>

#ifndef _DEBUG
#define cout               \
    if constexpr (true) {} \
    else                   \
        std::cout
#endif
