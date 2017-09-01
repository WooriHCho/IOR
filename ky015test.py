#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
read temperature and humidity from KY-015
"""
import RPi.GPIO as GPIO
import time

def bin2dec(string_num):
    return str(int(string_num, 2))

tempPin = 14

def read_data(pin):
    data = 0
    for i in range(8):
        if (GPIO.input(pin) == GPIO.LOW):
           # while (GPIO.input(pin) == GPIO.LOW):
            #    print("low")
             #   pass
            time.sleep(30 * 1e-6) 
            if (GPIO.input(pin) == GPIO.HIGH):
                data |= (1 << (7-i)) 
            while (GPIO.input(pin) == GPIO.HIGH):
                pass
    return data

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(tempPin, GPIO.OUT)

while True:
    GPIO.output(tempPin, GPIO.LOW);
    time.sleep(30 * 1e-6);
    GPIO.output(tempPin, GPIO.HIGH);
    time.sleep(40 * 1e-6); 
    GPIO.setup(tempPin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(tempPin, GPIO.IN)

    while (GPIO.input(tempPin) == GPIO.HIGH):
        pass
    time.sleep(80 * 1e-6) 
    if (GPIO.input(tempPin) == GPIO.LOW):
        pass
    time.sleep(80 * 1e-6);
    dat = range(8)
    for i in range(8):
        dat[i] =3
    for i in range(8):
        dat[i] = read_data(tempPin)
    GPIO.setup(tempPin, GPIO.OUT)
    GPIO.output(tempPin, GPIO.HIGH); 

  
    print('Current humidity: %3d.%d' % (dat[0], dat[1]))
    print('Current temperature: %3d.%dC' % (dat[2], dat[3]))
    time.sleep(1)
