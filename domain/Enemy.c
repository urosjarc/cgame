#include "Enemy.h"

Enemy enemy_new(int x, int y, int speed) {
    Enemy enemy;

    enemy.speed = speed;
    enemy.x = x;
    enemy.y = y;

    return enemy;
}


void enemy_print(Enemy *self) {
    printf("Enemy: %x", self);
    printf(" - speed: %i", self->speed);
    printf(" - posit: (%ix, %iy)\n", self->x, self->y);
}

void enemy_move(Enemy *self, int x, int y) {
    self->x += x*self->speed;
    self->y += y*self->speed;
}
