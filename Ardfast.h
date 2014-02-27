
#ifndef __Ardfast_H__
#define __Ardfast_H__

#include <arduino.h>

#define definePin(port, pin) { &port, (1 << pin) }
#define pinHigh(Pin) *Pin.portAddr |= Pin.pinMask
#define pinLow(Pin) *Pin.portAddr &= ~Pin.pinMask

#define pinOut(port, pin) port |= 1 << pin
#define pinIn(port, pin) port &= ~(1 << pin)

typedef struct Pin Pin;
struct Pin {
    volatile uint8_t* portAddr;
    uint8_t pinMask;
};

Pin createPin(uint8_t logicalPin);

void shiftOutMsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits);
void shiftOutLsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits);

#endif


