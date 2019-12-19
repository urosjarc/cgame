#include <stdio.h>
#include "Enemy.h"

int enemy_x_move_direction = 1;

Enemy enemy_new(int x, int y, int speed) {
    Enemy enemy;

    enemy.is_alive = 1;
    enemy.speed = speed;
    enemy.x = x;
    enemy.y = y;
    enemy.laser = laser_new(x, y, 1);

    return enemy;
}


void enemy_shot(Enemy *self) {
    self->laser.x = self->x;
    self->laser.y = self->y;
    self->laser.is_alive = 1;
}

void enemy_move_down(Enemy *self) {
    self->y += self->speed;
}

void enemy_move(Enemy *self) {
    self->x += enemy_x_move_direction * self->speed;
}
