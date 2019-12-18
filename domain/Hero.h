//
// Created by urosjarc on 15. 12. 19.
//

#ifndef CGAME_HERO_H
#define CGAME_HERO_H

#include "Laser.h"

typedef struct Hero {
    Laser laser;
    unsigned int kills;
    unsigned int lives;
    unsigned int speed;
    int x;
    int y;
} Hero;

Hero hero_new(int lives, int speed, int x, int y);
void hero_print(Hero *);
void hero_move(Hero *, int x, int y);
void hero_shot(Hero *pHero);

#endif //CGAME_HERO_H
