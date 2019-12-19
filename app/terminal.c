//
// Created by urosjarc on 16. 12. 19.
//

#include <ncurses.h>
#include <zconf.h>
#include "terminal.h"


int terminal_main(World *world, int enemy_speed, int laser_speed) {
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

        if(i%enemy_speed==0) {
            world_move_enemy(world);

            if(world->enemies[0].y == world->height)
                end = 1;
        }

        if(i%laser_speed == 0){
            int enemy_alive_num = world_move_hero_laser(world);
            if(enemy_alive_num == 0) {
                terminal_draw_world(world);
                terminal_msg(world, "You Won! :D");
                sleep(2);
                break;
            }
        }

        if(end){
            terminal_msg(world, "The End");
            sleep(2);
            break;
        }

        move(0, 0);
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
    for(int h=0;h<world->height+1;h++) mvaddch(h, hero.x, '|');
    mvaddch(hero.y, hero.x, '^');


    //PLACE HERO LASER
    if(hero.laser.is_alive) mvaddch(hero.laser.y, hero.laser.x, '^');

    //PLACE ENEMIES
    int enemy_num = world_enemy_num(world);
    for(int i=0;i<enemy_num-1;i++){
        Enemy enemy = world->enemies[i];
        if(enemy.is_alive) mvaddch(enemy.y, enemy.x, 'x');
    }
}

