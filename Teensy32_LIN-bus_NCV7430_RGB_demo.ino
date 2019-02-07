/*
 * This is a Teensy 3.2 LIN master controlling a NCV7430 RGB LED driver
 * 
 * http://skpang.co.uk/catalog/ncv7430-linbus-rgb-led-breakout-baord-p-1569.html
 * 
 * skpang.co.uk 2019
 * 
 * 
 */
#include "lin-bus.h"

#define SET_LED_CONTROL 0x23
#define SET_LED_COLOUR  0x24

int led = 13;
int lin_cs = 23;
int tx_pin = 1;

lib_bus lin(BAUD_19200,1);

uint8_t tx_buffer[8]; 

void init_ncv7430(void)
{
  tx_buffer[0] = 0xc0;
  tx_buffer[1] = 0x00;
  tx_buffer[2] = 0x00;
  tx_buffer[3] = 0x7f;
  tx_buffer[4] = 0;
 
  lin.write(SET_LED_CONTROL,tx_buffer,4);
}

void set_nvc7430_blue(void)
{
    tx_buffer[0] = 0xc0;
    tx_buffer[1] = 0x00;
    tx_buffer[2] = 0x00;
    tx_buffer[3] = 0x10;
    tx_buffer[4] = 0x31;  //Intensity Bit 3:0
    tx_buffer[5] = 0x00;   //green
    tx_buffer[6] = 0x00;   //Red
    tx_buffer[7] = 0xff;   //blue
 
    lin.write(SET_LED_COLOUR,tx_buffer,8);
}

void set_nvc7430_red(void)
{
        tx_buffer[0] = 0xc0;
        tx_buffer[1] = 0x00;
        tx_buffer[2] = 0x00;
        tx_buffer[3] = 0x10;
        tx_buffer[4] = 0x31;
        tx_buffer[5] = 0x00;  //green
        tx_buffer[6] = 0xff;  //Red
        tx_buffer[7] = 0x00;  //blue
     
        lin.write(SET_LED_COLOUR,tx_buffer,8);
}

void set_nvc7430_green(void)
{
        tx_buffer[0] = 0xc0;
        tx_buffer[1] = 0x00;
        tx_buffer[2] = 0x00;
        tx_buffer[3] = 0x10;
        tx_buffer[4] = 0x31;
        tx_buffer[5] = 0xff;  //green
        tx_buffer[6] = 0x00;  //Red
        tx_buffer[7] = 0x00;  //blue
     
        lin.write(SET_LED_COLOUR,tx_buffer,8);
}


void setup() 
{
  pinMode(led, OUTPUT);    
  pinMode(lin_cs, OUTPUT); 
  digitalWrite(led, HIGH);   
  digitalWrite(lin_cs, HIGH);    
  
  delay(1000);  
  Serial.begin(11520);            // Configure serial port for debug
  Serial.print("LIN-bus test");
   
  digitalWrite(led, LOW); 

  init_ncv7430();
}

void loop() 
{
   set_nvc7430_green();
   delay(200); 
   
   set_nvc7430_blue();
   delay(200); 
   
   set_nvc7430_red();

   digitalWrite(led, HIGH);   
   delay(100); 
   digitalWrite(led, LOW);  
   delay(100); 
}
