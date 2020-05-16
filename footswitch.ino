#include <EEPROM.h>

#define KEY_DELAY 50  // ms debounce
#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define BUTTON5 6
#define BUTTON6 7

int button1Status = 0;
int button2Status = 0;
int button3Status = 0;
int button4Status = 0;
int button5Status = 0;
int button6Status = 0;


void setup() 
{
    // setup serial port
    Serial.begin(1000000);

    // input switches
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
    pinMode(BUTTON3, INPUT_PULLUP);
    pinMode(BUTTON4, INPUT_PULLUP);
    pinMode(BUTTON5, INPUT_PULLUP);
    pinMode(BUTTON6, INPUT_PULLUP); 
}

void loop() 
{

        if(!digitalRead(BUTTON1))
        {
            if(button1Status == 0)
            {
                MIDImessage(0xB0, 0x55, 0x00);
                button1Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x55, 0x7F);
                button1Status = 0;
            }

            while(!digitalRead(BUTTON1)); // wait until button is released
            delay(KEY_DELAY);
        }

        if(!digitalRead(BUTTON2))
        {
            if(button2Status == 0)
            {
                MIDImessage(0xB0, 0x56, 0x00);
                button2Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x56, 0x7F);
                button2Status = 0;
            }

            while(!digitalRead(BUTTON2)); // wait until button is released
            delay(KEY_DELAY);
        }

        if(!digitalRead(BUTTON3))
        {
            if(button3Status == 0)
            {
                MIDImessage(0xB0, 0x57, 0x00);
                button3Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x57, 0x7F);
                button3Status = 0;
            }

            while(!digitalRead(BUTTON3)); // wait until button is released
            delay(KEY_DELAY);
        }

        if(!digitalRead(BUTTON4))
        {
            if(button4Status == 0)
            {
                MIDImessage(0xB0, 0x58, 0x00);
                button4Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x58, 0x7F);
                button4Status = 0;
            }

            while(!digitalRead(BUTTON4)); // wait until button is released
            delay(KEY_DELAY);
        }

        if(!digitalRead(BUTTON5))
        {
            if(button5Status == 0)
            {
                MIDImessage(0xB0, 0x59, 0x00);
                button5Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x59, 0x7F);
                button5Status = 0;
            }

            while(!digitalRead(BUTTON5)); // wait until button is released
            delay(KEY_DELAY);
        }

        if(!digitalRead(BUTTON6))
        {
            if(button6Status == 0)
            {
                MIDImessage(0xB0, 0x5A, 0x00);
                button6Status = 1;
            }
            else
            {
                MIDImessage(0xB0, 0x5A, 0x7F);
                button6Status = 0;
            }

            while(!digitalRead(BUTTON6)); // wait until button is released
            delay(KEY_DELAY);
        }
}


//send MIDI message
void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);//send note on or note off command 
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}
