#include "Ardfast.h"

void shiftOutMsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits)
{
    for (bits--; bits < 255; bits--)  
    {
        if((val & (1ul << bits)))
            pinHigh(dataPin);
        else
            pinLow(dataPin);

        pinHigh(clockPin);
        pinLow(clockPin);		
    }
}

void shiftOutLsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits)
{
    uint8_t n;
    
    for (n = 0; n < bits; n++)  
    {
        if((val & (1ul << n)))
            pinHigh(dataPin);
        else
            pinLow(dataPin);

        pinHigh(clockPin);
        pinLow(clockPin);		
    }
}

// convenience call to create Pin but costly on program space to bring in these other calls
Pin createPin(uint8_t logicalPin)
{
    Pin pin;
    
    pin.pinMask = digitalPinToBitMask(logicalPin);
    pin.portAddr = portOutputRegister(
        digitalPinToPort(logicalPin)
    );
    return pin;
}

