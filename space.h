#ifndef SPACE_H
#define SPACE_H


#include "globals.h"

struct Rock {
    int x, y, width = 3, height = 3;
    };


void spaceGame(int &score, int &NextScore, int &life, int &density, int &speed, std::vector<Rock> &rocks);

void boundary(int x, int y);
bool checkCollision(const Rock& rock);
void DisplayLife(int Life);
void RemoveOldRocks(std::vector<Rock>& rocks);
void RockGen(std::vector<Rock> &rocks, int density); 
void RockFall(std::vector<Rock> &rocks,int speed);
void invincibility_isr();


extern bool vulnrable;




#endif