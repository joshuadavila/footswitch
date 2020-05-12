#include <EEPROM.h>

bool buttonReleased = 0;
unsigned char buttonState[7];

void setup() 
{
    // setup serial port
    Serial.begin(1000000);

    // input switches
    for(int button = 2; button <= 7; button++)
    {
        pinMode(button, INPUT_PULLUP);
    }

    // output LEDs
    for(int led = 14; led <= 19; led++) pinMode(led, OUTPUT);
 

    // set LEDs status from saved EEPROM values
    for(int led = 14; led <= 19; led++)
    {   
        if(EEPROM.read(led))
        {
            digitalWrite(led, HIGH);
        }
        else
        {
            digitalWrite(led, LOW);
        }
    }

}

void loop() 
{
    for(int button = 2; button <=7; button++)
    {
        if(!digitalRead(button) && !buttonReleased)
        {
            buttonReleased = 1;
            if(EEPROM.read(button))
            {
                EEPROM.write(button, 0x00);
                sendMIDICC(0xB0, button + 0x53, 0x00);
            }
            else
            {
                EEPROM.write(button, 0xFF);
                sendMIDICC(0xB0, button + 0x53, 0xFF);
            }

            while(digitalRead(button)); // wait until button is released
            buttonReleased = 0;
        }
    }

}

void sendMIDICC(byte command, byte controller, byte value)
{
    Serial.write(command);
    Serial.write(controller);
    Serial.write(value);
}
