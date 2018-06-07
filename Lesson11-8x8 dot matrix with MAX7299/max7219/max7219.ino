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
*/

#include "MaxMatrix.h"
#include "mouths.h"
#include "gestures.h"

#define PIN_DIN    10   //max 7219
#define PIN_CS     11
#define PIN_CLK    12
MaxMatrix ledmatrix = MaxMatrix(PIN_DIN, PIN_CS, PIN_CLK, 1); //PIN  10=DIN, PIN 11=CS, PIN 12=CLK

void setup() {
  Serial.begin(9600);
  // set up Matrix display
  ledmatrix.init();
  ledmatrix.setIntensity(1);
  ledmatrix.writeFull(neutral);//display
  delay(1000);
  ledmatrix.writeFull(smile);
  delay(1000);
}

void loop() {
  ledmatrix.writeFull(Tears); //display
  delay(500);
  //ledmatrix.clearMatrix();
  //delay(500);              //Clear screen
}


