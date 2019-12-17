//
// Created by urosjarc on 16. 12. 19.
//

#include <ncurses.h>
#include <zconf.h>
#include "terminal.h"

int terminal_main(World *world) {
    //Init screen
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    refresh();

    //Main loop
    char key;
    for(int i=0; (key=getch()) != 'q';i++){
        terminal_draw_world(world);
        world_move_hero(world, key);
        if(i%10==0) world_move_enemies(world);
        usleep(1e4);
    }

    //End screen
    endwin();
    return 0;
}

void terminal_draw_world(World *world){

    //DRAW WORLD
    for(int h=0;h<world->height+1;h++){
        for(int w=1;w<world->width;w++)
            mvaddch(h, w, ' ');
        if(h<world->height){
            mvaddch(h, 0, '|');
            mvaddch(h, world->width, '|');
        }
    }

    //PLACE HERO
    Hero hero = world->hero;
    mvaddch(hero.y, hero.x, '^');

    //PLACE ENEMIES
    int enemy_num = world_enemy_num(world);
    for(int i=0;i<enemy_num-1;i++){
        Enemy enemy = world->enemies[i];
        mvaddch(enemy.y, enemy.x, 'x');
    }
}

