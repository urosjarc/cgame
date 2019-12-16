#include <stdio.h>
#include "Hero.h"

Hero hero_new(int lives, int speed, int x, int y){
    Hero hero;

    hero.speed = speed;
    hero.x = x;
    hero.y = y;

    hero.kills = 0;
    hero.lives = 1;

    return hero;
}

void hero_print(Hero *self) {
    printf("Hero: %x", self);
    printf(" - kills: %i", self->kills);
    printf(" - lives: %i", self->lives);
    printf(" - speed: %i", self->speed);
    printf(" - posit: (%ix, %iy)\n", self->x, self->y);
}

void hero_move(Hero *self, int x, int y){
    self->x += x*self->speed;
    self->y += y*self->speed;
}
