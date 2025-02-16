#include "globals.h"

// Define global variables (NO 'extern' here)
//class Joystick joystick(PC_3, PC_2);
InterruptIn buttonA(PC_12);
DigitalIn buttonUP(PD_2);  
DigitalIn buttonDOWN(PC_11);
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);

int targetx = 42;
int targety = 24;
int speed = 1;
int density = 15;
int life = 3;
int NextScore = 1000;
int clockCounter = 0;
int game = 0;
float y_pos = 24;
float x_pos = 42;
volatile int g_buttonA_flag = 0;
volatile int g_timer_flag = 0;
int score = 0;


void timer_isr(){
    g_timer_flag = 1;   // set flag in ISR
}

void buttonA_isr(){
    g_buttonA_flag = 1;   // set flag in ISR
}


void boundary(int x, int y){
    if (x < 1 ){        //ensure that the point doesnt pass beyond the left hand side of the screen
        x_pos = 1;
    }else if (x > 81){  //ensure that the point doesnt pass beyond the right hand side of the screen-
        x_pos = 81;
    }

    if(y < 1){          //ensure that the point doesnt pass beyond the top of the screen
        y_pos = 1;
    }else if(y > 45){   //ensure that the point doesnt pass beyond the bottom of the screen
        y_pos = 45;
    }
}
