#include "funcs.h"


void mutatorFunc(std::unique_ptr<int> pA)
{
    if (pA)
    {
        *pA = 10;
    }
}
