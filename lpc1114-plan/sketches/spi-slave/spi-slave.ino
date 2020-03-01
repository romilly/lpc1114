// Written by Nick Gammon
// February 2011


#include <SPI.h>


volatile char ip;
volatile boolean process_it;

void setup (void)
{
  Serial.begin (115200);   // debugging
  delay(1000);

  // turn on SPI in slave mode
  SPCR |= bit (SPE);

  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);

  // get ready for an interrupt
  process_it = false;
  Serial.println ("starting...");

  // now turn on interrupts
  
 
  SPI.attachInterrupt();
  
}  // end of setup


// SPI interrupt routine
ISR (SPI_STC_vect)
{
byte c = SPDR;  // grab byte from SPI Data Register
  
    ip = c;
    process_it = true;
    SPDR = '!';

}  // end of interrupt routine SPI_STC_vect

// main loop - wait for flag set in interrupt routine
void loop (void)
{
  if (process_it)
    {
    Serial.print(ip);
    process_it = false;
    }  // end of flag set

}  // end of loop
