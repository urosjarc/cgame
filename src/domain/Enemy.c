#include <stdio.h>
#include "Enemy.h"

int ENEMY_x_move_direction = 1;
int ENEMY_speed = 100;

Enemy enemy_new(int x, int y) {
    Enemy enemy;

    enemy.is_alive = 1;
    enemy.x = x;
    enemy.y = y;
    enemy.laser = laser_new(x, y);

    return enemy;
}


void enemy_shot(Enemy *self) {
    self->laser.x = self->x;
    self->laser.y = self->y + 1;
    self->laser.is_alive = 1;
}

void enemy_move_down(Enemy *self) {
    self->y++;
}

void enemy_move(Enemy *self) {
    self->x += ENEMY_x_move_direction;
}
