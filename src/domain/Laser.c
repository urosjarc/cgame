//
// Created by urosjarc on 16. 12. 19.
//

#include "Laser.h"

Laser laser_new(int x, int y, int speed) {
    Laser laser;

    laser.is_alive = 0;
    laser.x = x;
    laser.y = y;
    laser.speed = speed;

    return laser;
}

void laser_move(Laser *self, int x, int y) {
    self->x += x;
    self->y += y;
}
