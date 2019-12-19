#ifndef CGAME_LASER_H
#define CGAME_LASER_H

int LASER_speed;

typedef struct Laser {
    int is_alive;
    int x;
    int y;
} Laser;

Laser laser_new(int x, int y);

void laser_reset(Laser *);

void laser_move(Laser *, int x, int y);

int laser_killed(Laser *);

#endif //CGAME_LASER_H
