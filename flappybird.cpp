#include "flappybird.h"

int gravity = 5;
int velocity = 0;
int scale = 100;

bird player;
std::vector<pipe> pipes;



void flappybird() {

    while(1){
        lcd.clear();
        printf(" in flappybird \n");
        printf("height: %d", player.height);
        printf("  velocity: %d", player.velocity);
        

        if (g_buttonA_flag) {  
            ThisThread::sleep_for(500ms);
            g_buttonA_flag = 0;
            printf(" buttonA pressed \n");
            break;
            }

        if (buttonUP.read() && player.velocity > 0) {
            player.velocity = -100;
        }

        if (clockCounter % 1 == 0 ) { 
            player.velocity += gravity;
            player.height += player.velocity;
            for (auto &pipe : pipes) {
                pipe.distance -= speed;
                }
            }

        if (clockCounter % 20 == 0 ) {
            genPipe(pipes);
        }


        //displaying
        dispPipes();
       
        lcd.drawSprite(player.pos_x, player.height/scale, 8, 11, (int *)alien);
    
        if (player.height > HEIGHT * scale) {
            player.height = 0;
            printf("            Reset height ");
        }
        

        clockCounter++;
        lcd.refresh();
        ThisThread::sleep_for(10ms);
        }
}


void genPipe(std::vector<pipe> &pipes) {
    pipes.push_back({rand() % HEIGHT, 10, WIDTH});
    //pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
    //    [](const pipe& p) { return p.distance < 0; }), pipes.end());
}

void dispPipes() {
    for (const auto &pipe : pipes) { //draws all rocks
        if (pipe.distance > 0 ) {
            lcd.drawRect(pipe.distance, pipe.height, 10, HEIGHT, FILL_BLACK); 
            printf("   :  %d", pipe.height);
        } else {
            pipes.erase(pipes.begin());
        }
    }
}