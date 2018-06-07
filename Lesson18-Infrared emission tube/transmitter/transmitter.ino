/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]      Infrared transmitter module
 * [Diagram]
 *         Arduino PIN 3    ===================  Infrared transmitter module pin S
 *         Arduino PIN GND  ===================  Infrared transmitter module pin -
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin2
 */
#define ADD 0x00
int TRAM_PIN = 3; //define input pin on Arduino 
void setup() {
    Serial.begin(9600);
    pinMode(TRAM_PIN, OUTPUT);
} 
void loop() {
	uint8_t dat, temp;
	if ( Serial.available()) {
		temp = Serial.read();
		IR_Send38KHZ(280, 1);//Send 9ms start code
		IR_Send38KHZ(140, 0);//Send a 4.5ms result code

		IR_Sendcode(ADD);//User ID
		dat = ~ADD;
		IR_Sendcode(dat);//User ID reverse code

		IR_Sendcode(temp);//Operation code
		dat = ~temp;
		IR_Sendcode(dat);//Opcode inversion

		IR_Send38KHZ(21, 1);//Send end code
	}
	delay(200);
}
void IR_Send38KHZ(int x, int y) { //Generates 38KHZ infrared pulses
	for (int i = 0; i < x; i++) { //15=386US 
		if( y == 1){
			digitalWrite(TRAM_PIN, 1);
			delayMicroseconds(9);
			digitalWrite(TRAM_PIN, 0);
			delayMicroseconds(9);
		}
		else {
			digitalWrite(TRAM_PIN, 0);
			delayMicroseconds(20);
		}
	}
}
void IR_Sendcode(uint8_t x) {
    for (int i = 0; i < 8; i++) {
       if ( (x&0x01) == 0x01) {
           IR_Send38KHZ(23, 1);
           IR_Send38KHZ(64, 0);
        }
        else {
            IR_Send38KHZ(23, 1);
            IR_Send38KHZ(21, 0);
        }
    x = x >> 1;
    }
}
