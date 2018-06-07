/***********************************************************************
         __                                                          _
        / /        _____  __    __  _          _   (_)   ________   | |
       / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
      / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
     / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
    / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
   /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|


   KeyWiwh Tech firmware  github:https://github.com/keywish/keywish-arduino-nano-super-kit

   Copyright (C) 2015-2020

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, in version 3.
   learn more you can see <http://www.gnu.org/licenses/>.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [Title]:   RGB breathing light
 * [Diagram]
 *         Arduino PIN 11  ===================   RGB pin1 red
 *         Arduino PIN 10  ===================   RGB pin3 green
 *         Arduino PIN 9   ===================   RGB pin4 blue
 *         Arduino PIN 8   ===================   Buzzer positive wire
 *         Arduino GND     ===================   RGB pin2  GND
 *
 */

#define RGB_RED    11
#define RGB_GREEN  10
#define RGB_BLUE   9

#define Do 262  
#define Re 294  
#define Mi 330  
#define Fa 349  
#define Sol 392  
#define La 440  
#define Si 494  
#define Do_h 523  
#define Re_h 587  
#define Mi_h 659  
#define Fa_h 698  
#define Sol_h 784  
#define La_h 880  
#define Si_h 988

int buzzer = 8;   // buzzer pin 9
int length;
// happy birthday Music score

void setColor(int red,int green,int blue)
{
    analogWrite(RGB_RED,red);
    analogWrite(RGB_GREEN,green);
    analogWrite(RGB_BLUE,blue);
}


int scale[] = {Sol, Sol, La, Sol, Do_h, Si, Sol, Sol,
               La, Sol, Re_h, Do_h, Sol, Sol, Sol_h, Mi_h,
               Do_h, Si, La, Fa_h, Fa_h, Mi_h, Do_h, Re_h, Do_h }; 

// Beats time
float durt[]=
{
    0.5, 0.5, 1, 1, 1, 1+1, 0.5, 0.5,
    1, 1, 1, 1+1, 0.5, 0.5, 1, 1,
    1, 1, 1, 0.5, 0.5, 1, 1, 1, 1+1
};


void setup()
{
    pinMode(buzzer, OUTPUT);
    // get scale length
    length = sizeof(scale) / sizeof(scale[0]);
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    for(int x = 0; x < length; x++) {
        // Serial.println(scale[x]);
        tone(buzzer, scale[x]);
        setColor(scale[x] - 425, scale[x] - 500, scale[x] - 95);
        // 1= 3/4F so one Beats is  187*4 = 748ms
        delay(748 * durt[x]);
        noTone(buzzer);
    }
    delay(3000);
}

