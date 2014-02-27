ArduinoOptimized
================

This is a work in progress.  

This small library is intended to reduce the size of my sketches and make them run much faster.
The default calls like digitalWrite, pinMode and shiftOut are slow and large in terms of code space.


digitalWrite
	Method has been replaced with 3 macros.

	pinHigh(pin), pinLow(pin) which operates on a Pin struct.
	definePin(port, port pin) which creates a Pin struct

Pin - struct

	The struct is intended to avoid typos in specifying port and port in as well as abstracting it.
	It also performs the necessary operations up front to determine the port address and bit offset.

	There are 3 ways to create a Pin, in this example my digital pin 5 is on PORTD, PD5.

	Pin clock = definePin(PORTD, PD5);    // preferred
	Pin clock = { &PORTD, _BV(PD5) };     // manual way
	Pin clock = createPin(5);             // convenience method but consumes code space

pinMode 
	Method has been replaced with 2 macros.
	
	pinOut(port, port pin)
	pinIn(port, port pin)
	
shiftOut
	Method has been replaced with new method.  It operates on the Pin struct and up to 32 bits of data.
	
	void shiftOutMsb(Pin dataPin, Pin clockPin, unsigned long val, uint8_t bits)
