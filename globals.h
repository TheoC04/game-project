#ifndef GLOBALS_H
#define GLOBALS_H

#include "mbed.h"
#include <vector>
#include "Joystick.h" 
#include "N5110.h"

// Declare external global variables Any file that includes globals.h can use these variables.
extern Joystick joystick;
extern InterruptIn buttonA;
extern DigitalIn buttonUP;
extern DigitalIn buttonDOWN;
extern N5110 lcd;  

extern int targetx;
extern int targety;
extern int speed;
extern int density;
extern int life;
extern int NextScore;
extern int clockCounter;
extern int game;
extern float y_pos;
extern float x_pos;
extern volatile int g_buttonA_flag;
extern volatile int g_timer_flag ;
extern int score;

void boundary(int x, int y);
void timer_isr();
void buttonA_isr();


#endif  // GLOBALS_H