import serial
from TwilioCommunicator import executeTwilio
                                                                                #imports time module required for delays (sleep functions)
arduino = serial.Serial('/dev/ttyACM0', 9600)                                         #Creates arduino object and establishes connection to port (Enter your port)
x = 0
while x != 1:
    results = arduino.readline()
    try:
        print(str(results))
        if results != '':
            twilio = executeTwilio()
            break
    except:
        print()
    
        #print('Calling 911')"""
    


