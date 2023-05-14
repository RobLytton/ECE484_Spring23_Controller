
For my individual final project in ECE484 I made an arduino game controller that communicates to another arduino that controls a python script through the serial port.

I did this by taking the first Arduino and using this 433MHz RX and TX module:
https://www.twinschip.com/RF_Wireless_433Mhz
with an arduino joystick and a few pushbuttons. The tx will be on the portable is able to send 11 commands 9 based on the direction of the joy sticks and 2 for the buttons

On the receiving side there is an rx module that receives this command and prints them to the computer console using a python script

I could not get the serial communication to work in java so I used python

In the future I will make it in java to use for my personal game. I made in java with a keylistener class that gets input from the keyboard. I will make a class that listens for commands from the serial port to replace the keyboard output. 

This is an interest I have because whenever me and my friends play my game we have to pass the computer back and forth which can get old and this will make it more portable.

