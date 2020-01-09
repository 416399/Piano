//***************** SONG 4 NOTES HERE **************************
void Song4()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("  SONG 4 TITLE");
     
      

      int thisNote = 0;

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      for (int thisNote = 0; thisNote < 8; thisNote++) { 
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(8, melody[thisNote], noteDuration);
      
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(8); // stop the tone playing:
        } // end for


Song4title();

  
  } // end Song4 loop
