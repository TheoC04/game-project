#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include "globals.h"
#include "sprites.h"


struct pipe {
    int height;
    int gap;
    int distance;
};

struct bird {
    int height = 30;
    int velocity = 0;
    int pos_x = 20;
};


void flappybird();

void genPipe(std::vector<pipe> &pipes);
void dispPipes();
void collision();






#endif