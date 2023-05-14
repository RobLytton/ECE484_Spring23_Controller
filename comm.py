import serial
import time
ser = serial.Serial('COM10', 9600, timeout = 0)
print(ser.name)
time.sleep(2)
line = ''
while(True):
    line = ser.read(ser.inWaiting())
    if(str(line) != "b\'\'"):
        if(int(line) == 1):
            print("UP")
        elif(int(line) == 2):
            print('UP RIGHT')
        elif(int(line) == 3):
            print('RIGHT')
        elif(int(line) == 4):
            print('DOWN RIGHT')
        elif(int(line) == 5):
            print('DOWN')
        
        elif(int(line) == 6):
            print("DOWN LEFT")
        elif(int(line) == 7):
            print('LEFT')
        elif(int(line) == 8):
            print('UP LEFT') 
        elif(int(line) == 9):
            print('BUTTON 1')
        elif(int(line) == 10):
            print('BUTTON 2')
        elif(int(line) == 11):
            print('BUTTON 3')
        else:
            print('STOP')
