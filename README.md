
For my individual final project in ECE484 I made an arduino game controller that communicates to another arduino that controls a python script through the serial port.

I did this by taking the first Arduino and using this 433MHz RX and TX module:
https://www.twinschip.com/RF_Wireless_433Mhz
with an arduino joystick and a few pushbuttons. The tx will be on the portable is able to send 11 commands 9 based on the direction of the joy sticks and 2 for the buttons

On the receiving side there is an rx module that receives this command and prints them to the computer console using a python script

This will print the message of the sent command to the screen.

This is an interest I have because whenever me and my friends play my game we have to pass the computer back and forth which can get old and this will make it more portable.

Schematic for controller with transmitter, buttons, and joystick:

![Console](https://github.com/RobLytton/ECE484_Spring23_Controller/assets/92745408/ed4824ed-b32b-452e-a2fd-0aaaf0e5f780)

Schematic for console with reciever, LEDs, buzzer and LCD:

![Controller](https://github.com/RobLytton/ECE484_Spring23_Controller/assets/92745408/236660da-ff91-4a74-96ff-93c87847469d)


Here is a video link to a live demo: 

https://youtu.be/JbdTxnZAwcU?si=iawSBIZ2GPSAdH0F
