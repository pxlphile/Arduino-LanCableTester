# Arduino-LanCableTester
A LAN cable tester with an active and a passive part, based upon an Arduino Nano

The wiring diagram is straight forward. Basically the trick lies in the idea that only one digital pin is HIGH at one time, all the others are low. That means they act like a GROUND pin. There is a fast LED start sequence and then every LED should be lighted, one after another, from LED #1 till #8.

There's a drawback in this schematic. When a cable core inside the LAN cable is broken/disconnected then at least two LEDs don't work anymore.
![Wiring diagram](https://pxlphile.github.io/Arduino-LanCableTester/LanCableTester_diagram.svg)

The breadboard should look like this.
![Breadboard diagram](https://pxlphile.github.io/Arduino-LanCableTester/LanCableTester_breadboard.svg)

