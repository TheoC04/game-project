
#include "menu.h"

int menu(int state) {
    while (1) {
        lcd.clear();

        bool up = buttonUP.read();
        bool down = buttonDOWN.read();

        printf(" \n new frame:        "); // new line of debug printouts
        printf("state: %d", state);

        const int NUM_STATES = 4;
        State menu_fsm[NUM_STATES] = {
            {1, "Menu", {1,3}},
            {2, "GAME1", {2,0}},
            {3, "GAME2", {3,1}},
            {4, "GAME3", {0,2}},
            };
        
        if (up) {
            state = menu_fsm[state].next_state[1];
            printf(" UP PRESSED");
        }
        if (down) {
            state = menu_fsm[state].next_state[0];
            printf(" DOWN PRESSED ");
        }
        state = state % NUM_STATES;

        for (int i = 0; i < NUM_STATES; i++) {  // Loop over all states
        if (i == state) {
            lcd.printString("> ", 2, i);  // Highlight selected option
            }
        lcd.printString(menu_fsm[i].name, 7, i);
        }

        if (g_buttonA_flag) {  
            ThisThread::sleep_for(500ms);
            g_buttonA_flag = 0;
            printf(" buttonA pressed \n");
            return state;
            }

        lcd.refresh();
        ThisThread::sleep_for(50ms);
    }
}