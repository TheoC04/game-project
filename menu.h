#ifndef MENU_H
#define MENU_H

#include "mbed.h"
#include "globals.h"

struct State {
    int id;
    const char* name;
    int next_state[2];
};

int menu(int state);

#endif