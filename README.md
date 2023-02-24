
My proposal for my individual final project is an arduino game controller that communicates to another arduino that controls a java program through the serial port.

I will do this by taking the first Arduino and using this 433MHz RX and TX module:
https://www.twinschip.com/RF_Wireless_433Mhz
with an arduino joystick and a few pushbuttons. The tx will be on the portable controller that will be powered by a 9V battery and will be able to send 11 commands 9 based on the direction of the joy sticks and 2 for the buttons

On the receiving side I will have the rx module receive this command and print them to the serial monitor using a java class

I have a personal game I made in java with a keylistener class that gets input from the keyboard. I will make a class that listens for commands from the serial port to replace the keyboard output. 

This is an interest I have because whenever me and my friends play my game we have to pass the computer back and forth which can get old and this will make it more portable.

If I have extra time some improvements I will add are adding lights and sounds based on the commands sent and also solder an antenna on the modules to increase the  range of the controller 
