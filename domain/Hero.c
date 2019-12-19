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
    hero.laser = laser_new(x, y, 1);

    return hero;
}

void hero_move(Hero *self, int x, int y){
    self->x += x*(int)self->speed;
    self->y += y*(int)self->speed;
}

void hero_shot(Hero *hero) {
    hero->laser.x = hero->x;
    hero->laser.y = hero->y;
    hero->laser.is_alive = 1;
}

