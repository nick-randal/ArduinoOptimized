
#ifndef __Ardfast_H__
#define __Ardfast_H__

#include <arduino.h>

// ------------ Standard ----------------------------

#define setRegister(port, pin) port |= (1 << pin)
#define clrRegister(port, pin) port &= ~(1 << pin)
#define getRegister(port, pin) (port & (1 << pin))

#define _pinHigh(num) setRegister(out ## num, d ## num)
#define  pinHigh(num) _pinHigh(num)
#define _pinLow(num)  clrRegister(out ## num, d ## num)
#define  pinLow(num)  _pinLow(num)
#define _pinIn(num)   clrRegister(dir ## num, d ## num)
#define  pinIn(num)   _pinIn(num)
#define _pinOut(num)  setRegister(dir ## num, d ## num)
#define  pinOut(num)  _pinOut(num)
#define _isHigh(num)  getRegister(in ## num, d ## num)
#define  isHigh(num)  _isHigh(num)

// ------------ Pin ----------------------------
typedef struct Pin Pin;
struct Pin {
    volatile uint8_t* outRegister;
    uint8_t pinMask;
};

Pin createPin(uint8_t logicalPin);

#define definePin(port, pin) { &port, (1 << pin) }
#define setPinHigh(PinStruct) *PinStruct.outRegister |= PinStruct.pinMask
#define setPinLow(PinStruct) *PinStruct.outRegister &= ~PinStruct.pinMask

void shiftOutMsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits);
void shiftOutLsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits);

#endif


