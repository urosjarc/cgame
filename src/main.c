#include <stdio.h>

#include "World.h"
#include "terminal.h"


int main() {

    World world = world_new(1);
    return terminal_main(&world, 100, 10);
}

