# footswitch
Arduino midi foot switch controller

this project contains all the information needed to modify an existing footswitch (Marshall JMD:1 footswitch) in order to make it a MIDI compatible USB footswitch based on Arduino Uno.

This project uses the MocoLUFA firmware to make the arduino serial interface a usb-midi bridge.
http://morecatlab.akiba.coocan.jp/lab/index.php/aruino/midi-firmware-for-arduino-uno-moco/?lang=en

In regard to the arduino firmware it's basically an state machine that scans input switches and send the corresponding MIDI CC# parameter, toggling the sent value every time switch is activated. 0x00 value represents disable state and 0x7F represents the active state.
