#include "Ardfast.h"

void shiftOutMsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits)
{
    for (bits--; bits < 255; bits--)  
    {
        if((val & (1ul << bits)))
            setPinHigh(dataPin);
        else
            setPinLow(dataPin);

        setPinHigh(clockPin);
        setPinLow(clockPin);		
    }
}

void shiftOutLsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits)
{
    uint8_t n;
    
    for (n = 0; n < bits; n++)  
    {
        if((val & (1ul << n)))
            setPinHigh(dataPin);
        else
            setPinLow(dataPin);

        setPinHigh(clockPin);
        setPinLow(clockPin);		
    }
}

// convenience call to create Pin but costly on program space to bring in these other calls
Pin createPin(uint8_t logicalPin)
{
    Pin pin;
    
    pin.pinMask = digitalPinToBitMask(logicalPin);
    pin.outRegister = portOutputRegister(
        digitalPinToPort(logicalPin)
    );
    return pin;
}

