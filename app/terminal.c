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
    int end = 0;
    for(int i=0; (key=getch()) != 'q';i++){

        terminal_draw_world(world);
        world_event(world, key);

        if(i%10==0) {
            world_move_enemy(world);

            if(world->enemies[0].y == world->height)
                end = 1;
        }

        if(i%10 == 0)
            world_move_hero_laser(world);

        if(end){
            terminal_msg(world, "The End");
            sleep(2);
            break;
        }
        usleep(1e4);
    }

    //End screen
    terminal_msg(world, "Good Bye");
    sleep(2);

    endwin();
    return 0;
}

void terminal_msg(World *world, char *msg) {
    mvaddstr(world->height/2, world->width/2 - (int)sizeof(msg)/sizeof(char)/2, msg);
    refresh();
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

    //PLACE HERO LASER
    mvaddch(hero.laser.y, hero.laser.x, '^');

    //PLACE ENEMIES
    int enemy_num = world_enemy_num(world);
    for(int i=0;i<enemy_num-1;i++){
        Enemy enemy = world->enemies[i];
        mvaddch(enemy.y, enemy.x, 'x');
    }
}

