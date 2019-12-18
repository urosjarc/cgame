#include <stdio.h>
#include "Hero.h"
#include "Laser.h"

Hero hero_new(int lives, int speed, int x, int y){
    Hero hero;

    hero.lives = lives;
    hero.speed = speed;
    hero.x = x;
    hero.y = y;

    hero.kills = 0;
    hero.lives = 1;
    hero.laser = laser_new(x, y, 0);

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
    self->x += x*(int)self->speed;
    self->y += y*(int)self->speed;
}

void hero_shot(Hero *hero) {
    hero->laser.x = hero->x;
    hero->laser.y = hero->y;

    if(hero->laser.speed == 0)
        hero->laser.speed = 1;
}

