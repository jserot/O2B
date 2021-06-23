#include <stdint.h>
#include <stdbool.h>

#ifndef PI_SF_REG_H
#define PI_SF_REG_H



bool read_bit(uint8_t reg, uint8_t bit);
void set_bit(uint8_t reg, uint8_t bit);
void clear_bit(uint8_t reg, uint8_t bit);
void write_register(uint8_t reg, uint8_t val);
uint8_t read_register(uint8_t reg);
void delay(int ms);
int millis();

#endif
