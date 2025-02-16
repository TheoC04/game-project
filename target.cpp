#include "target.h"
#include <string>
#include "sprites.h"



void game2(int &clockCounter, int &targetx, int &targety) {
    //DEBUG print statements
    printf("\n targetx: %d", targetx);
    printf("   targety: %d", targety);



    //for (int target ; target < targets ; target++){
        if (clockCounter % 100 == 0 ) {
            randomPoint(targetx, targety);
        }
    //}
    
    lcd.drawSprite(targetx, targety, 12, 12, (int *)target);
    drawCrosshair(x_pos, y_pos, 5);
    std::string scoreString = std::to_string(score); //these 3 lines print the score on the top right
    const char* cstr = scoreString.c_str();
    lcd.printString(cstr , 60, 0);
    
    if (buttonUP.read()) {
            printf(" UP pressed\n");
            if (x_pos < targetx + 12 &&
                x_pos > targetx &&
                y_pos < targety + 12 &&
                y_pos > targety) {
                    score++;
                    randomPoint(targetx, targety);
            }
        }
    if(joystick.get_direction() == N){
            y_pos--;
            printf(" Direction: N\n");

            }else if(joystick.get_direction() == S){
                y_pos++;
                printf(" Direction: S\n");
            
            }else if(joystick.get_direction() == E){
                x_pos++;
                printf(" Direction: E\n");

            }else if(joystick.get_direction() == W){
                x_pos--;
                printf(" Direction: W\n");

            }else if(joystick.get_direction() == NE){
                y_pos--;
                x_pos++;
                printf(" Direction: NE\n");

            }else if(joystick.get_direction() == NW){
                y_pos--;
                x_pos--;
                printf(" Direction: NW\n");

            }else if(joystick.get_direction() == SE){
                y_pos++;
                x_pos++;
                printf(" Direction: SE\n");

            }else if(joystick.get_direction() == SW){
                y_pos++;
                x_pos--;
                printf(" Direction: SW\n");
            } else {


                   //printf(" Direction: Centre\n");
    }
    boundary(x_pos, y_pos);
}


void randomPoint(int &x, int &y) {
    x = rand() % WIDTH - 6;
    y = rand() % HEIGHT - 6;
}


void drawCrosshair(int x, int y, int size) {
    lcd.drawLine(x + 2, y, x + size, y, FILL_BLACK);   //east
    lcd.drawLine(x - 2, y, x - size, y, FILL_BLACK);   //west
    lcd.drawLine(x , y + 2, x , y + size, FILL_BLACK); //south
    lcd.drawLine(x , y - 2, x, y - size, FILL_BLACK);  //north

}