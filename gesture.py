import serial
from subprocess import call

arduinoData = serial.Serial('/dev/ttyUSB0', 9600)

def input_handler(arduino_signal):
	if arduino_signal.strip() == "A":
		asignal()
	elif arduino_signal.strip() == "B":
		bsignal()
	else:
		print(arduino_signal)
		return

def asignal():
	call('gnome-terminal')
		
def bsignal():
	call('emacs')


while True:
    while (arduinoData.inWaiting() < 1):
        pass
    arduinoString = (arduinoData.readline()).decode('utf-8')
    input_handler(arduinoString)

    
    
