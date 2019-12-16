#ifndef CGAME_LASER_H
#define CGAME_LASER_H

typedef struct Laser {
    unsigned int speed;
    int x;
    int y;
} Laser;

Laser laser_new(int x, int y, int speed);
void laser_print(Laser *);

void laser_move(Laser *, int x, int y);


#endif //CGAME_LASER_H
