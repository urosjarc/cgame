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
} World;

World world_new();

void world_new_enemies(World *);

void world_event(World *, char key);

void world_move_enemy(World *);

int world_move_hero_laser(World *);

int world_move_enemy_lasers(World *);

int world_enemy_num(World *);

#endif //CGAME_WORLD_H
