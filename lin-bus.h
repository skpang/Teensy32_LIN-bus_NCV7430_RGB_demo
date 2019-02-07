#include <Arduino.h>

#define BAUD_19200  19200
#define BAUD_9600   9600

class lib_bus
{
  
    public:
  // Constructors
  lib_bus(uint16_t baudrate, uint8_t Tx_pin); // Constructor for Master Node
  
  int write(uint8_t ident, uint8_t data[], uint8_t data_size);
  int write_request(uint8_t ident);
  int read_request(uint8_t data[], uint8_t data_size);
  
  private:
  const unsigned int period = 96; // in microseconds, 1s/10417
  uint8_t addrParity(uint8_t addr);
  uint8_t dataChecksum(const uint8_t* message, uint8_t nBytes,uint16_t sum);
  uint8_t tx_pin;
  uint16_t kbps;
  uint16_t bit_len;
  
};
