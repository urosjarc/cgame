//
// Created by urosjarc on 15. 12. 19.
//

#ifndef CGAME_HERO_H
#define CGAME_HERO_H

#include "Laser.h"


int HERO_speed;
int HERO_lives;
int HERO_points;

typedef struct Hero {
    Laser laser;
    int lives;
    int speed;
    int x;
    int y;
} Hero;

Hero hero_new(int lives, int x, int y);

void hero_move(Hero *, int x, int y);

void hero_shot(Hero *pHero);

#endif //CGAME_HERO_H
