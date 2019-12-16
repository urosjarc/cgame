//
// Created by urosjarc on 16. 12. 19.
//

#include "World.h"

World world_new(int enemy_num, int speed) {
    World world;

    world.height = 20;
    world.width = 20;

    world.hero = hero_new(1, 1, 0, 0);
    hero_print(&world.hero);

    for(int i=0;i<enemy_num;i++){
        world.enemies[i] = enemy_new(0, 0, speed);
        enemy_print(&world.enemies[i]);
    }

    return world;
}

void world_next_move(World *self) {

    int enemy_num = sizeof(self->enemies)/ sizeof(Enemy);

    for(int i=0;i<enemy_num;i++){
        enemy_move(&self->enemies[i], 1, 0);
    }

}
