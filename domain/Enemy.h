//
// Created by urosjarc on 15. 12. 19.
//

#ifndef CGAME_ENEMY_H
#define CGAME_ENEMY_H

typedef struct Enemy {
    unsigned int speed;
    int x;
    int y;
} Enemy;

Enemy enemy_new(int x, int y, int speed);
void enemy_print(Enemy *);
void enemy_move(Enemy *, int x, int y);

#endif //CGAME_ENEMY_H
