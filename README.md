# GameGlove
![game glove](https://github.com/Cheezegami/GameGlove/blob/master/GameGlove.jpg?raw=true)

# Concept
The game glove is a wearable glove device that's used to play games. You equip it by putting your hand into the glove and connecting the battery to the Vin and GND. You hold the thumbstick under your wise and middle finger in order to control it with your thumb.


It was an iterative process and I tried various ways of implementing the code and concept. Originally I tried to read the time with the modulo operator, but since the arduino timer is inconsistent I went and did the blink without delay approach.


The glove concept was something that popped inside of me after thinking about the concept some more. Originally I intended to make a fortune telling machine, but since I lost my lcd panel I went and made a small game using the LED matrix, after that I thought about the portability of this concept and thought of ways to keep it more and more portable.


Eventually I disconnected it from the PC and went for an external (9v) power supply.

I also added the Buzzer to create a better game feel and response to the game.


Some other interactions I've thought of but are not included as of this version are :

Finger Sensitivity Controls : Instead of a joystick the glove itself measures the axis of a finger.

Bigger LCD Panel : Instead of using the led matrix a bigger panel could be used to display more advanced games.

Game Tracking / Scoreboard : The game itself now doesn't show you your progress, a panel to indicate this could be an option.

Other Sensors : There are a variety of other sensors such as heat, laser and sound sensors that could be used to create more functionality towards the concept.

# Components
Electronics

1x 9v Battery.

1x 9v Battery Snap Connector.

1x (Full sized) Breadboard

1x Arduino Uno 

1x Buzzer

1x Led Matrix

1x Thumbstick


5x female to male jumper wires (To connect Thumbstick)

11x male to male jumper wires(not including 9v connector)


Other:

1 Roll of strong double sided tape.

1 Winter Glove (optional with a Velcro Band on the wrist) 

(Optional) : Tie rips for wire management.

# Assembly Guide
NOTE: Make sure to only use the rightmost 5 cm of your breadboard so that the other components such as the arduino, band and 9v battery are able to rest on the rest of the breadboard, if you're unsure, place the 3 components on the breadboard 

1.- make sure you have a wire connected to the red strip on the breadboard reading +, these are for energizing your components and will be used later in the tutorial.
So connect a male jumper wire from the 5v on the arduino to the plus sign on the breadboard.
Also connect a male jumper wire from the ground on the arduino to the minus sign on the breadboard.

2.- Make sure the led matrix is soldered and connect it to the assigned ports on the Arduino.

(+) - Connect the plus (leftmost fit) to the plus strip on the breadboard)

(-) - Connect the minus (next to it) to the minus strip on the breadboard)

(D) - Connect the d (second to the right) to the Analogue 4 on the Arduino)

(C) - Connect the c (most right) to the Analogue 5 on the Arduino)


3.- Connect the buzzer

Make sure the buzzer is connected to the digital pin 9 (customizable in code) and the ground with an optional resistor.


4.- Connect the joystick

Make sure the joystick uses 5 all female to male wires, the switch has been connected to analogue 2, while the x and y have been connected to 0 and 1 respectively. Furthermore, the +5 and GND have been connected to the breadboard's + and - stripes respectively.


5.- Connect the battery

Make sure the battery is connected to the 9v snap connector and put the red wire (+) into the 5v Vin and the black one (-) into the second ground slot. This will make sure the Arduino has sufficient energy. (Feel free to pull these two wires out if you want to prevent your battery from draining.


6.- Connect to the glove
It's important that you have a strong two sided tape now.
Put the battery sideways on the leftmost (opposide of your cables and installation) part of the breadboard and tape it to the board with the double sided tape.
Then leave a margin for the Vectro band of your glove (if neccessary) if you don't have this you should try to use double sided tape underneath here instead.
Next thing you do is tape the Arduino as far left as you can without obstructing the (optional) Vectro band). If you don't have a Vectro band, put it next to the battery.


6.1 (Optional) Tie rip your wires together so that they are less all over the place.


7.- Run the code on the Arduino.
Upload the sampled code on your Arduino and Wham, you have just made your own GameGlove.

# Concept Choices


