
For my individual final project in ECE484 I made an arduino game controller that communicates to another arduino that controls a python script through the serial port.

I did this by taking the first Arduino and using this 433MHz RX and TX module:
https://www.twinschip.com/RF_Wireless_433Mhz
with an arduino joystick and a few pushbuttons. The tx will be on the portable is able to send 11 commands 9 based on the direction of the joy sticks and 2 for the buttons

On the receiving side there is an rx module that receives this command and prints them to the computer console using a python script

This will print the message of the sent command to the screen.

This is an interest I have because whenever me and my friends play my game we have to pass the computer back and forth which can get old and this will make it more portable.

Schematic for controller with transmitter, buttons, and joystick:

<img width="1230" height="700" alt="image" src="https://github.com/user-attachments/assets/83c9bf8a-49ad-4bea-a060-5e57457fe01c" />


Schematic for console with reciever, LEDs, buzzer and LCD:

<img width="891" height="867" alt="image" src="https://github.com/user-attachments/assets/8bd8750e-730f-4952-9828-6fa351575f9a" />





Here is a video link to a live demo: 

https://youtu.be/JbdTxnZAwcU?si=iawSBIZ2GPSAdH0F
