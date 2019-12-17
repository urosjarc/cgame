//
// Created by urosjarc on 16. 12. 19.
//

#include <stdlib.h>
#include "terminal.h"

void terminal_draw_world(World *world){

    char cord[world->height][world->width];
    int enemy_num = world_enemy_num(world);
    Hero hero = world->hero;

    //CREATE EMPTY WORLD
    for(int h=0;h<world->height;h++){
        for(int w=0;w<world->width;w++){
            cord[h][w] = ' ';
        }
    }

    //PLACE ENEMIES
    for(int i=0;i<enemy_num-1;i++){
        Enemy enemy = world->enemies[i];
        cord[enemy.y][enemy.x] = 'x';
    }

    //PLACE HERO
    cord[hero.y][hero.x] = '^';

    //DRAW WORLD
    terminal_clear();
    for(int h=0;h<world->height;h++){
        putchar('|');

        for(int w=0;w<world->width;w++){
            putchar(cord[h][w]);
        }
        putchar('|');
        putchar('\n');
    }

    putchar('\n');
}

void terminal_clear() {
    for(int i=0;i<20;i++) printf("\n");
}
