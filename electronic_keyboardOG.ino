// LCD Screen, Switch & LED Setup
#include <LiquidCrystal.h>
#include "pitches.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int LCDswitchPin = 7; // define menu/LCD switch name
int LCDswitchState = 0; // set menu/LCD switch state to off/low
int prevLCDswitchState = 0;
int blueLED = 6;
int LCDswitchCounter = 0;   // counter for the number of menu button presses 
    // (this code counts the menu button pushes, displays them on your computer, 
    // and starts from zero after ending "menu mode". currently has no other effect 
    // on this sketch, but is a good starting point for expanding on the project with 
    // new features later    

// Music Note Keys - Set frequency values
int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Set notes C, D, E, F, G, A, B



//////////////////////////////////////////////
void setup() {
  
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  pinMode(LCDswitchPin, INPUT);
  pinMode(blueLED, OUTPUT);
  digitalWrite(blueLED, LOW); // LED stays off while piano keys are on
  

} // end setup


//////////////////////////////////////////////
void loop() {
  
  LCDswitchState = digitalRead(LCDswitchPin);
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  lcd.noDisplay();
  digitalWrite(blueLED, LOW); // Turn LED back off every time main loop starts
  


// ************** START "LCDstart" WHEN MENU BUTTON IS PUSHED ***********

    if (LCDswitchState == HIGH)  {
      digitalWrite(blueLED, HIGH); // Turn LED on to show piano keys are disabled and device is in "menu mode"
      lcd.display();
      lcd.clear();
      LCDstart();
      }
   
   
// ***********************************************************************
  
  

////// KEYBOARD NOTES & FREQUENCY STATEMENTS //////
// Use the resistor ladder you created to change the voltage of each piano key button
// 220 ohm = C5 // 560 ohm = D5 // 1K ohm = E5 // etc...
  if(keyVal == 1023)  {
    tone(8, notes[0]); // C
    } // end if
    
        else if(keyVal >= 990 & keyVal <=1010)  {
          tone(8, notes[1]); // D
          } // end else if
    
        else if(keyVal >= 960 && keyVal <= 980)  {
          tone(8, notes[2]); // E
          } // end else if
        
        else if(keyVal >= 900 && keyVal <= 945)  {
          tone(8, notes[3]); // F
          } // end else if
        
        else if(keyVal >= 650 && keyVal <= 710)  {
          tone(8, notes[4]); // G
          } // end else if
        
        else if(keyVal >= 500 && keyVal <= 550)  {
          tone(8, notes[5]); // A
          } // end else if
        
        else if(keyVal >= 5 && keyVal <= 10)  {
          tone(8, notes[6]); // B
          } // end else if
        
        else if(keyVal <= 1)  { // if no switch is pressed, do not play tone
          noTone(8);
          } // end else if

} //end frequency tone loop





/////////////////////////////////////////////////////
void LCDstart()  {
  int keyVal = analogRead(A0);  
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button

    while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed
      LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button every time loop starts
      
      //************* START SONG 1 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 1
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song1title();
        lcd.clear();
        break;
        }

      //************* ELSE SHOW MENU ****************
      else   {  // if menu button is not pressed, then...
        LCDswitchCounter=0; // set menu button count to 0
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WHICH SONG WOULD");
        lcd.setCursor(0, 1);
        lcd.print("YOU LIKE TO PLAY");
        delay(50); // return to main 
        }
     
      } // end while
  } // end LCDstart loop
  
  
  

// ************* SONG 1 LOOP STARTS HERE **************  
void Song1title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 2 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 2
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song2title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed   
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song1();
           break;
           } // end if
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SUPER MARIO BROS");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
    } // end while song 1 -> 2
        
} // end Song1title loop




// ************* SONG 2 LOOP STARTS HERE **************  
void Song2title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 3 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 3
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song3title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song2();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("SUPER MARIO BROS");
          lcd.setCursor(0, 1);
          lcd.print("   UNDERWORLD");
          delay(50);
          }
        
        } // end while song 2 -> 3
        
} // end Song2title loop




// ************* SONG 3 LOOP STARTS HERE **************  
void Song3title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 4
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song4title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song3();
           break;
           } // end if
           
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    JEOPARDY");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
        
        } // end while song 3 -> 4
        
} // end Song3title loop





// ************* SONG 4 LOOP STARTS HERE **************  
void Song4title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 5 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 5
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more

        Song5title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song4();
           break;
           } // end if
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 4");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song4title loop




// ************* SONG 5 LOOP STARTS HERE **************  
void Song5title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter=0; // set button count to 0
        Serial.print("number of button pushes:  ");
        Serial.println(LCDswitchCounter);
        delay(300); // min. time until counts adds 1 more
        lcd.clear();
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
        Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(blueLED, LOW);
           Song5();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("     SONG 5");
          lcd.setCursor(0, 1);
          lcd.print("   TITLE HERE");
          delay(50);
          }
        
        } // end while song 4 -> 5
        
} // end Song5title loop







