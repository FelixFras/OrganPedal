## Organ Pedal

### Discription

I connected wires from every pedal into the arduino throught a pull down resistor. The contact area where every pedal makes contact when being pressed is connected to 5v. If the pedal is pressed the pedal will act as a switch and create a high signal at the input pin of the arduino nano. This signal can then be used to send the correct midi message out through the midi port which is connected with 5v through a 220O resistor using pin 4, with TX1 through a 220O resistor using pin 5 and ping 2 is connected to ground. In addition to that I also added a switch to change octaves.

### Code

The program checks constantly whether a button is pressed or let go. If a pedal is being pressed a midi note start signal for the right key is being sent through the output. When the pedal is no longer being pressed a midi note stop signal is being sent.  
The octave switching button will stop all midi notes and will then change the octave either one octave higher or lower.  
The while loops and delays are there to prevent bouncing.

![project image](/midiorgan.jpg)
