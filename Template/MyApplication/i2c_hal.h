#ifndef __I2C_HAL_H
#define __I2C_HAL_H

#include "stm32g4xx_hal.h"

void I2CStart(void);
void I2CStop(void);
unsigned char I2CWaitAck(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2CInit(void);

void eeprom_wirte(uint8_t *eeprom_string, uint8_t address, uint8_t number);
void eeprom_read(uint8_t *eeprom_string, uint8_t address, uint8_t number);
void mcp4017_write(uint8_t data);
void mcp4017_read(uint8_t *data);

#endif
