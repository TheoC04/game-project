
#include "space.h"
#include "sprites.h"
#include <string>

bool vulnrable = true;
Timeout invinibilityTimeout;

//std::vector<Rock> rocks;

void spaceGame(int &score, int &NextScore, int &life, int &density, int &speed, std::vector<Rock> &rocks) {
    


    if (score > NextScore) {
            NextScore += 500;
            density -= 2;
            speed++;
            life++;
        }

    if (g_timer_flag) {
                    g_timer_flag = 0;  // if it has, clear the flag
                    RockGen(rocks, density);
                    RockFall(rocks,speed);  
                    score += 1; 
                }

    lcd.drawSprite(x_pos,y_pos,8,11,(int *)alien);
    DisplayLife(life);

    std::string scoreString = std::to_string(score); //these 3 lines print the score on the top right
    const char* cstr = scoreString.c_str();
    lcd.printString(cstr , 60, 0);
    RemoveOldRocks(rocks);

    for (const auto &rock : rocks) { //draws all rocks
        lcd.drawRect(rock.x,rock.y + 5,rock.width,rock.height, FILL_BLACK); 
    }
    for (const auto& rock : rocks) {   //checks colision with rocks
        if (checkCollision(rock) && vulnrable) { 
            //lcd.drawRect(42, 24, 22, 3, FILL_BLACK);
            vulnrable = false;
            life--;
            invinibilityTimeout.attach(&invincibility_isr,1000ms);
            if (life==-1) {
                life = 3;
            }
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
    boundary(x_pos, y_pos); //stops player from ging of screen
}

void RockGen(std::vector<Rock> &rocks, int density) {
    if (rand() % density == 0) { // Random chance to generate a new rock
        rocks.push_back({rand() % WIDTH, 0});
    }
}

void RockFall(std::vector<Rock> &rocks, int speed) {
    for (auto &rock : rocks) {
        if (rock.y < HEIGHT + 10) {
            rock.y += speed;
        }
    }
}

bool checkCollision(const Rock& rock) {  // player is 11x8 
    return (x_pos < rock.x + rock.width &&
            x_pos + 11 > rock.x &&
            y_pos < rock.y + rock.height &&
            y_pos + 9 > rock.y);
}

void invincibility_isr() {
    g_timer_flag = 1;
    vulnrable = true;
}


void DisplayLife(int Life) {
    switch (Life) {
    case 0: {
        lcd.drawSprite(2, 2, 7, 7, (int* )heartEmpty);
        lcd.drawSprite(11, 2, 7, 7, (int* )heartEmpty);
        lcd.drawSprite(20, 2, 7, 7, (int* )heartEmpty);
        break;
    }
    case 1: {
        lcd.drawSprite(2, 2, 7, 7, (int* )heartFull);
        lcd.drawSprite(11, 2, 7, 7, (int* )heartEmpty);
        lcd.drawSprite(20, 2, 7, 7, (int* )heartEmpty);
        break;
    }
    case 2: {
        lcd.drawSprite(2, 2, 7, 7, (int* )heartFull);
        lcd.drawSprite(11, 2, 7, 7, (int* )heartFull);
        lcd.drawSprite(20, 2, 7, 7, (int* )heartEmpty);
        break;
    }
    case 3: {
        lcd.drawSprite(2, 2, 7, 7, (int* )heartFull);
        lcd.drawSprite(11, 2, 7, 7, (int* )heartFull);
        lcd.drawSprite(20, 2, 7, 7, (int* )heartFull);
        break;
    }
    }
}

void RemoveOldRocks(std::vector<Rock>& rocks) {
    rocks.erase(std::remove_if(rocks.begin(), rocks.end(),
        [](const Rock& r) { return r.y > 48; }), rocks.end());
}
