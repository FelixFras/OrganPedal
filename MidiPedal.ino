const int PIN_BUTTON_1 = 2;  // Define the starting pin for buttons
const int NUM_BUTTONS = 13;  // Define the number of buttons
int velocity = 100; // Velocity of MIDI notes, must be between 0 and 127
int noteON = 144; // Note on command
int noteOFF = 128; // Note off command
int startingNote = 60-12; // Starting MIDI note (C4)
bool pressed[NUM_BUTTONS]; // Array to store the state of each button

void setup() 
{
  Serial.begin(31250); // Set MIDI baud rate

  // Set each button pin as input
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(PIN_BUTTON_1 + i, INPUT);
    pressed[i] = false;
  }
}

void loop() 
{
  // Check the state of each button
  for (int i = 0; i < NUM_BUTTONS; i++) 
  {
    if (digitalRead(PIN_BUTTON_1 + i) == HIGH) // If the button is pressed
    {
      if (!pressed[i]) // If it wasn't pressed before
      {
        MIDImessage(noteON, startingNote + i, velocity); // Send MIDI note on
        pressed[i] = true;
      }
    }
    else // If the button is not pressed
    {
      if (pressed[i]) // If it was pressed before
      {
        MIDImessage(noteOFF, startingNote + i, velocity); // Send MIDI note off
        pressed[i] = false;
      }
    }
  }
  
  // delay to prevent bouncing
  delay(10);
}


void MIDImessage(int command, int MIDInote, int MIDIvelocity) 
{
  Serial.write(command); // Send note on or note off command 
  Serial.write(MIDInote); // Send pitch data
  Serial.write(MIDIvelocity); // Send velocity data
}
