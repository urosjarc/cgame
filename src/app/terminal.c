//
// Created by urosjarc on 16. 12. 19.
//

#include <ncurses.h>
#include <zconf.h>
#include "terminal.h"
#include <stdlib.h>

int terminal_main() {

    World world = world_new(HERO_lives);

    for (int j = 0; j < 3; j++) {

        if(j!=0) world = world_new(world.hero.lives);

        char key;
        int end = 0;
        for (int i = 0; (key = getch()) != 'q'; i++) {

            terminal_draw_world(&world);
            terminal_draw_infos(&world);
            world_event(&world, key);

            if (i % ENEMY_speed == 0) {
                world_move_enemy(&world);

                if (world.enemies[0].y == world.width)
                    end = 1;
            }
            if (i % LASER_speed == 0) {

                int hero_hit = world_move_enemy_lasers(&world);
                int enemy_alive_num = world_move_hero_laser(&world);

                if (!enemy_alive_num) {
                    terminal_draw_world(&world);
                    terminal_msg(&world, "You Won! :D", 2);
                    break;
                }

                if(hero_hit && !world.hero.lives){
                    terminal_draw_infos(&world);
                    terminal_msg(&world, "GAME OVER!", 2);
                    break;
                }


            }

            if (end) {
                terminal_msg(&world, "The End", 2);
                break;
            }

            move(0, 0);
            usleep(1e4);
        }

        if (j == 2) terminal_msg(&world, "Good Bye", 2);
    }

    endwin();
    return 0;
}

void terminal_init() {
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    refresh();
}

void terminal_msg(World *world, char *msg, int slp) {
    mvaddstr(world->height / 2, (int)((world->width - (float)sizeof(msg) / sizeof(char)) / 2), msg);
    refresh();
    sleep(slp);
}

void terminal_draw_world(World *world) {

    //DRAW WORLD
    for (int h = 0; h < world->height + 1; h++) {
        for (int w = 1; w < world->width; w++)
            mvaddch(h, w, ' ');
        if (h < world->height) {
            mvaddch(h, 0, '|');
            mvaddch(h, world->width, '|');
        }
    }

    //PLACE HERO
    Hero hero = world->hero;
    for (int h = 0; h < world->height + 1; h++) mvaddch(h, hero.x, '|');
    mvaddch(hero.y, hero.x, '^');


    //PLACE HERO LASER
    if (hero.laser.is_alive) mvaddch(hero.laser.y, hero.laser.x, '^');

    //PLACE ENEMIES
    int enemy_num = world_enemy_num(world);
    for (int i = 0; i < enemy_num; i++) {
        Enemy enemy = world->enemies[i];
        Laser laser = enemy.laser;
        if (enemy.is_alive) mvaddch(enemy.y, enemy.x, 'x');
        if (laser.is_alive) mvaddch(laser.y, laser.x, '*');
    }
}

void terminal_draw_infos(World *world) {
    char lives[10];
    char points[10];
    sprintf(lives, "Lives: %i", world->hero.lives);
    sprintf(points, "Points: %i", HERO_points);
    mvaddstr(world->height+1, 0, lives);
    mvaddstr(world->height+2, 0, points);
    refresh();
}

