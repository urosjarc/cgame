#include <stdio.h>
#include "Hero.h"
#include "Laser.h"

int HERO_speed = 100;
int HERO_lives = 3;
int HERO_points = 0;

Hero hero_new(int lives, int x, int y) {
    Hero hero;

    hero.lives = lives;
    hero.x = x;
    hero.y = y;

    hero.laser = laser_new(x, y);

    return hero;
}

void hero_move(Hero *self, int x, int y) {
    self->x += x;
    self->y += y;
}

void hero_shot(Hero *hero) {
    hero->laser.x = hero->x;
    hero->laser.y = hero->y;
    hero->laser.is_alive = 1;
}

