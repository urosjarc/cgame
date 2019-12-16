#include <stdio.h>
#include <stdlib.h>
#include "domain/World.h"
#include "app/terminal.h"


int main() {

    World world = world_new(9, 1);
    world_next_move(&world);

    terminal_draw_world(&world);

    return 0;
}

