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
 *         Arduino PIN 11   ===================  Infrared transmitter module pin Y
 *         Arduino PIN GND  ===================  Infrared transmitter module pin G
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin R
 */
#include <IRremote.h> 
int RECV_PIN = 11; //define input pin on Arduino 
IRrecv irrecv(RECV_PIN); 
decode_results results; 
void setup() { 
    Serial.begin(9600); 
    irrecv.enableIRIn(); // Start the receiver 
} 
void loop() { 
	if ( irrecv.decode( &results)) {
		if ( results.value == 16747635) {
			Serial.println("1");  //Received the number 1. Afterwards and so on
		}
		else if ( results.value == 16731315) {
			Serial.println("2");
		} 
		else if ( results.value == 16763955) {
			Serial.println("3");
		} 
		else if ( results.value == 16723155) {
			Serial.println("4");
		} 
		else if ( results.value == 16755795) {
			Serial.println("5");
		} 
		else if ( results.value == 16739475) {
			Serial.println("6");
		} 
		else if ( results.value == 16772115) {
			Serial.println("7");
		} 
		else if ( results.value == 16719075) {
			Serial.println("8");
		} 
		else if ( results.value == 16751715) {
			Serial.println("9");
		} 
		else if ( results.value == 16714995) {
			Serial.println("0");
		} 
		irrecv.resume(); // Receive the next value 
	} 
}
