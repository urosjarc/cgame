//
// Created by urosjarc on 16. 12. 19.
//

#include "World.h"
#include "Enemy.h"

World world_new(int speed) {
    World world;

    int enemy_num = world_enemy_num(&world);
    world.height = 10;
    world.width = 20;

    world.hero = hero_new(1, 1, world.width / 2, world.height - 1);
    hero_print(&world.hero);

    for (int i = 0; i < enemy_num; i++) {
        world.enemies[i] = enemy_new(i, 0, speed);
        enemy_print(&world.enemies[i]);
    }

    return world;
}

void world_next_move(World *self) {

    int enemy_num = world_enemy_num(self);
    int enemy_wall_collision = 0;

    if ((enemy_x_move_direction == 1 && self->enemies[enemy_num - 1].x == self->width) ||
        (enemy_x_move_direction == -1 && self->enemies[0].x == 0)) {

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

int world_enemy_num(World *self) {
    return sizeof(self->enemies) / sizeof(Enemy);
}
