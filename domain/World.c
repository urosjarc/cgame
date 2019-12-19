//
// Created by urosjarc on 16. 12. 19.
//

#include <ncurses.h>
#include "World.h"
#include "Enemy.h"

World world_new(int speed) {
    World world;

    int enemy_num = world_enemy_num(&world);
    world.height = 10;
    world.width = 20;

    world.hero = hero_new(1, 1, world.width / 2, world.height);

    for (int i = 0; i < enemy_num; i++)
        world.enemies[i] = enemy_new(i + 1, 0, speed);

    return world;
}

void world_move_enemy(World *self) {

    int enemy_num = world_enemy_num(self);
    int enemy_wall_collision = 0;

    if ((enemy_x_move_direction == 1 && self->enemies[enemy_num - 1].x == self->width) ||
        (enemy_x_move_direction == -1 && self->enemies[0].x == 1)) {

        enemy_wall_collision = 1;
        enemy_x_move_direction *= -1;
    }

    for (int i = 0; i < enemy_num; i++) {
        Enemy *enemy = &self->enemies[i];

        if (enemy_wall_collision) {
            enemy_move_down(enemy);
        } else enemy_move(enemy);
    }

}

void world_event(World *self, char key) {

    //MOVING HERO
    Hero *hero = &self->hero;
    int dx = 0;
    if (key == 'h' && hero->x > 1) dx = -1;
    else if (key == 'l' && hero->x < self->width - 1) dx = 1;
    else if (key == 'x' && !hero->laser.is_alive) {
        hero_shot(hero);
    }
    hero_move(hero, dx, 0);

}

int world_move_hero_laser(World *self) {
    Laser *laser = &self->hero.laser;
    //MOVING HERO LASER
    if (laser->speed > 0) {
        laser_move(laser, 0, -1);
        if (laser->y == -1) {
            laser->is_alive = 0;
        }
    }

    //CHECK LASER COLLISION WITH ENEMY
    int enemy_num = world_enemy_num(self);
    int enemy_alive_num = 0;
    for (int i = 0; i < enemy_num; i++) {
        Enemy *enemy = &self->enemies[i];
        if (enemy->is_alive) {
            enemy_alive_num++;
            if (enemy->x == laser->x && enemy->y == laser->y) {
                enemy->is_alive = 0;
                laser->is_alive = 0;
                enemy_alive_num--;
            }
        }
    }

    return enemy_alive_num;
}

int world_enemy_num(World *self) {
    return sizeof(self->enemies) / sizeof(Enemy);
}

void world_move_enemy_lasers(World *self) {
    int laser_num = world_enemy_num(self);
    for(int i=0;i<laser_num;i++){
        Laser *laser = &self->enemies[i].laser;
        //MOVING HERO LASER
        if (laser->is_alive) {
            laser_move(laser, 0, 1);
            if (laser->y == 0) {
                laser->is_alive = 0;
            }
        }
    }
}
