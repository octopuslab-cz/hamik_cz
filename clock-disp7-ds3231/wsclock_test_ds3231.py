print("--- octopusLAB: test_rtc_hw ---")

print("-> imports")
from time import sleep
from machine import Pin, SPI, Timer, RTC
from utils.octopus_lib import i2c_init
import ds3231 # https://github.com/peterhinch/micropython-samples/tree/master/DS3231


print("init")

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
    now = (2022, 6, 21, 6, 16, 20, 0, 0)
    rtc.datetime(now)
    ds3231.save_time()


rtc = RTC()
# ---------------------
#ds3231_init(ds, rtc)
# ---------------------

print("rtc.datetime-old", rtc.datetime())
print(ds.get_time(True))
print("rtc.datetime-now", rtc.datetime())

print("-"*30)  
        
while True:
    sleep(10)
    
    datetime = rtc.datetime()
    print("datetime", datetime[4], ":", datetime[5])



