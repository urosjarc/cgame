#include <stdio.h>

#include "domain/World.h"
#include "app/terminal.h"


int main() {

    World world = world_new(1);
    return terminal_main(&world, 100, 10);
}

