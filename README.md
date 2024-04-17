# temp-and-hum-on-4-7-segment
So, I've put together this neat little project that measures both temperature and humidity using an Arduino and a DHT11 sensor. Let me break it down for you:

First up, the DHT11 sensor. It's a handy little device that gives us accurate readings of temperature and humidity. It's great because it's affordable and does the job well.

Next, we've got the Arduino microcontroller. This is like the brains behind the operation. It takes the data from the DHT11 sensor and decides what to do with it.

And finally, we have a 4-slot 7-segment display. This is where we see the results. When you're not pressing the button, it shows you the temperature. But when you do press the button, it switches over to displaying the humidity level. It's a nice touch that adds some user interaction to the project.

So, all in all, it's a simple but effective system for keeping tabs on the temperature and humidity in your environment.

The pin connection is as follows:
connect the A to G and deccimal pins of segment to 0 to 7 pins of arduino.
D1 --> 8
D2 --> 9
D3--> 10
D4 --> 11

Give a 3.3 V and gnd to dht11 sensor and signal pin to the 12 pin of arduino 

Connect the switch to pin 13 of arduino and ground.

Note: if the code is not getting uploaded into the arduino remove the pins 0 and 1 and plug them after the code is uploaded.

