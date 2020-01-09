//***************** SONG 3 NOTES HERE **************************
void Song3()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
	NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2,
	NOTE_C3, NOTE_F3, NOTE_C3,
	NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
	NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
	NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2, NOTE_A2, // repeat line 1 and 2
	NOTE_C3, NOTE_F3, NOTE_C3,
	NOTE_AS3, 0, NOTE_G3, NOTE_F3,
	NOTE_E3, NOTE_D3, NOTE_CS3, NOTE_C3};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
	4,    4,    4,    8,   8,
	4,    4,          2,
	4,    4,    4,    4,
	3,    8,    8,    8,    8,   8,
	4,    4,    4,    8,    8, // repeat line 1 and 2
	4,    4,          2,
	4,    8,    8,    4,    4,
	4,    4,    4,    4,
	0};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("    JEOPARDY");
     
      

  for (int thisNote = 0; noteDurations[thisNote] != 0; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration * 0.9);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
	delay(noteDuration);
  }


Song3title();

  
  } // end Song3 loop
