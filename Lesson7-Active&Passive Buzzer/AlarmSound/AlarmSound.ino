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


   [Title]    product two frequeces sound
   [diagram]
             Arduino  pin8  ===================   buzzer positive wire

*/
void setup()  
{  
    pinMode(8,OUTPUT);  
}  
void loop()  
{  
    for(int i = 200; i <= 800; i++)   // 200HZ ~ 800HZ  
    {  
        tone(9,i);
    }  
    delay(1000);                    //Max Frequency hold 1s   
    for(int i= 800; i >= 200; i--)   // 800HZ ~ 200HZ
    {  
        tone(9,i);  
        delay(10);  
    }  
}