//
// Created by urosjarc on 16. 12. 19.
//

#include "Laser.h"

Laser laser_new(int x, int y, int speed){
    Laser laser;

    laser.x = x;
    laser.y = y;
    laser.speed = speed;

    return laser;
}

void laser_print(Laser *self){
    printf("Laser: %x", self);
    printf(" - speed: %i", self->speed);
    printf(" - posit: (%ix, %iy)\n", self->x, self->y);
}

void laser_move(Laser *self, int x, int y){
    self->x += x;
    self->y += y;
}
