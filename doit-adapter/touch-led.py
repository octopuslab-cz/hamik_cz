# ESP32 - DoIt simple example
#  Touch and LED
print("init")
from time import sleep
from machine import Pin, TouchPad

touch = TouchPad(Pin(4))
led = Pin(2, Pin.OUT)
buttonHeld = 0.0
led_value = False

print("start")

while True:
  button_read = touch.read()
  if button_read < 300: 
        print("button held for {0} s.".format(buttonHeld), button_read)
        buttonHeld += 0.1 
  elif buttonHeld > 0.0:
        print("Button pressed! Resetting phase.", end=" ")
        buttonHeld = 0
  if buttonHeld > 1.0:  # long_press           
     led.value(led_value)             
     print("Turned {0}".format("on." if led_value else "off."), end=" ")
     led_value = not led_value
     buttonHeld = 0
  sleep(0.1)