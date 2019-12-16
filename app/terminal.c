//
// Created by urosjarc on 16. 12. 19.
//

#include "terminal.h"

void terminal_draw_world(World *world){

    //Todo: You stayed here!
    char cord[world->width][world->height];

    for(int w=0;w<world->width;w++){
        putchar('|');

        for(int h=0;h<world->height;h++){
            putchar('x');
        }
        putchar('|');
        putchar('\n');
    }

}
