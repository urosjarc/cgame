#include <stdio.h>
#include "Enemy.h"

int enemy_x_move_direction = 1;

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

void enemy_move_down(Enemy *self) {
        self->y += self->speed;
}

void enemy_move(Enemy *self) {
    self->x += enemy_x_move_direction * self->speed;
}
