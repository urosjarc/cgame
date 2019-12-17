//
// Created by urosjarc on 16. 12. 19.
//

#include "Hero.h"
#include "Enemy.h"
#include "Laser.h"

#ifndef CGAME_WORLD_H
#define CGAME_WORLD_H

typedef struct World {
    int width;
    int height;
    Hero hero;
    Enemy enemies[9];
    Laser lasers[21];
} World;

World world_new(int speed);
void world_next_move(World *self);
int world_enemy_num(World *self);

#endif //CGAME_WORLD_H
