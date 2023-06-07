#include <stdio.h>
#include <vector>
#include <memory>

#include "funcs.h"

int main
(
    int     argc,
    char   *argv[]
)
{
    (void)argc;
    (void)argv;

    std::unique_ptr<int> ptr = std::make_unique<int>(1);
    *ptr = 5;

    printf("%d\n", *ptr);

    mutatorFunc(std::move(ptr));

    // We expect a segmentation fault here for derefing a NULL pointer (resource was explicity moved)
    printf("%d\n", *ptr);
}
