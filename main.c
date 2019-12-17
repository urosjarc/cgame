#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "domain/World.h"
#include "app/terminal.h"

int main() {
    int kord[10][10];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            kord[i][j] = i*j;
        }
    }

    World world = world_new(1);
    terminal_draw_world(&world);

    while(1){
        usleep(0.5e6);
        world_next_move(&world);
        terminal_draw_world(&world);
    }


    return 0;
}

