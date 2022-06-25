# count down example
from time import sleep
from utils.octopus import disp7_init

print("this is simple Micropython example | ESP32 & octopusLAB")
print()

d7 = disp7_init()   # 8 x 7segment display init

sleep(2)
while True:
  for i in range(9999999):
    d7.show("-"+str(1000000-i)+"-")
    sleep(0.01)