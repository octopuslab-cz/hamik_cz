print("--- octopusLAB: test_rtc_hw ---")

print("-> imports")
from time import sleep
from machine import Pin, SPI, Timer, RTC
from utils.pinout import set_pinout
from components.display7 import Display7
from utils.octopus_lib import i2c_init
import ds3231 # https://github.com/peterhinch/micropython-samples/tree/master/DS3231


print("init")
pinout = set_pinout()

print("--- spi_init")
spi = SPI(1, baudrate=10000000, polarity=1, phase=0, sck=Pin(pinout.SPI_CLK_PIN), mosi=Pin(pinout.SPI_MOSI_PIN))
ss = Pin(pinout.SPI_CS0_PIN, Pin.OUT)
#spi.deinit() #print("spi > close")

print("-> display7-init")
d7 = Display7(spi, ss) # 8 x 7segment display init
d7.write_to_buffer('octopus')
d7.display()
sleep(2)

print("-> display7-test")
for i in range(6):
    d7.show(5-i)
    sleep(0.1)

print("-"*30)

print("--- i2c_init")
i2c = i2c_init()
i2c.scan()
sleep(1)

print("time init")
ds = ds3231.DS3231(i2c)

def rtc_hw_init():
   # setup datetime (year, month, day, weekday, hour, minute, second, millisecond)
   datetime = urtc.datetime_tuple(year=2022, month=6, day=21, hour=15, minute=30, second=09)
   rtc_hw.datetime(datetime)
   
    
def ds3231_init(ds3231, rtc):
    now = (2022, 6, 22, 6, 21, 20, 0, 0)
    rtc.datetime(now)
    ds3231.save_time()


rtc = RTC()
# ---------------------
# ds3231_init(ds, rtc)
# ---------------------

print("rtc.datetime-old", rtc.datetime())
print(ds.get_time(True))
print("rtc.datetime-now", rtc.datetime())

print("-"*30)

def add0(sn):
    return "0"+str(sn) if int(sn)<10 else str(sn)
    
    
while True:
    datetime = rtc.datetime()
    print("datetime", datetime[4], ":", datetime[5])
    d7.show(add0(str(datetime[4])) + "-" + add0(str(datetime[5])) + "-" + add0(str(datetime[6])))
    sleep(0.25)    
   


