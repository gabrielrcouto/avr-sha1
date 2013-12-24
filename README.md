SHA-1 for AVR microcontroller
==============

I used this implementation of SHA-1: http://www.faqs.org/rfcs/rfc3174.html

The objective of this project is to test the speed of SHA-1 algorithm on microcontrollers. To do this, the microcontroller calculates 10 times the SHA-1 of a simple string ("ABC"), then echoes "g". 

Testing
==============

- Run the test for 30 seconds

- Get the times that G was echoed

- Divide times by 30, now you have the Hashes/second rate.

Results
==============

Microcontroller - Clock - Hashes/second

ATMEGA8 - 8MHz (internal oscillator) - 17 Hashes/second

TO DO
==============

- Use some AVR instructions

- Optimize for "cpu" usage

- Try to develop Scrypt algorithm too

Author
==============

[R3C Web](http://www.r3c.com.br)

[@gabrielrcouto](http://www.twitter.com/gabrielrcouto)

License
==============

[MIT License](http://zenorocha.mit-license.org/)
