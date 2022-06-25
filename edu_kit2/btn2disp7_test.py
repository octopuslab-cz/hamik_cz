# btn test (uPy v.1.18 on 2022-06-08: ok)
from time import sleep
from machine import Pin
from utils.pinout import set_pinout
from components.led import Led
from components.button import Button
from utils.octopus import disp7_init

print("this is simple Micropython example | ESP32 & octopusLAB")
print("-"*30)

print("init")

pinout = set_pinout()
pin34 = Pin(34, Pin.IN)
pin35 = Pin(35, Pin.IN)

button_led = Button(Pin(0), release_value=1)
button_lef = Button(pin34, release_value=1)
button_rig = Button(pin35, release_value=1)

d7 = disp7_init()   # 8 x 7segment display init
built_in_led = Led(2, Pin.OUT)

built_in_led.value(1)
sleep(1)
built_in_led.value(0)


@button_led.on_press
def on_press_top_button():
    print("on_press_top_button")
    built_in_led.on()
    sleep(1)
    built_in_led.off()


@button_lef.on_release
def on_press_lef():
    global num
    num -= 1
    print("left",num)
    

@button_rig.on_press
def on_press_rig():
    global num
    num += 1
    print("right",num)
    
num = 1000

sleep(2)
while True:
    d7.show("--"+str(num)+"--")
    sleep(0.1)
