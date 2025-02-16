#include "mbed.h"
#include "Joystick.h" 
#include "N5110.h"
#include "globals.h"
#include "menu.h"
#include "sprites.h"
#include "target.h"
#include "space.h"
#include "flappybird.h"
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

void init();
 
Joystick joystick(PC_3, PC_2);

std::vector<Rock> rocks;
Ticker ticker;


int main()
{

    init();

    ticker.attach(&timer_isr,150ms);

    while (true) {              //loop to show title screen tll buttonA is pressed          
        if (g_buttonA_flag) {
            g_buttonA_flag = 0;
            printf(" start \n");
            break;
        }
    }

    while (1) {
        lcd.clear();

        //menu(game);
        //spaceGame(score, NextScore, life, density, speed, rocks);

        switch (game) {
            case 0:{
                game = menu(game);
                printf("returned: %d", game);
                break;
            }
            case 1: {
                spaceGame(score, NextScore, life, density, speed, rocks);
                break;
            }
            case 2: {
                game2(clockCounter, targetx, targety);
                break;
            }
            case 3: {
                flappybird();
                printf("playing: %d", game);
                break;
            }
        }

        if (g_buttonA_flag) {  //logic to go back to menu
            g_buttonA_flag = 0;
            //score = 0;
            game = 0;
            printf(" buttonA pressed \n");
            }
        
        
        clockCounter++;
        lcd.refresh();
        ThisThread::sleep_for(20ms);
    }
}



void init() {
    joystick.init();
    lcd.init(LPH7366_1);        //initialise for LPH7366-1 LCD (Options are LPH7366_1 and LPH7366_6)
    lcd.setContrast(0.55);      //set contrast to 55%
    lcd.setBrightness(0.5);     //set brightness to 50% (utilises the PWM)
    
    buttonA.rise(&buttonA_isr);
    buttonA.mode(PullDown);
    buttonUP.mode(PullDown);
    buttonDOWN.mode(PullDown);

    lcd.drawSprite(0,0,48,84,(int *)titleScreen);
    lcd.refresh();

}
