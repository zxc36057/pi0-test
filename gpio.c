#include "gpio.h"
#include "uart.h"
void gpio_select(const unsigned pin, const gpio_function_t mode) {
    register unsigned int r;

    // The register index starting at GPFSEL0.
    const unsigned int index = (pin * 0xcdU) >> 11;
    // Amount to shift to get to the required pin bits.
    const unsigned int shift = (pin - index * 10) * 3;
    
    // Calculate the GPFSEL register that contains the configuration for
    // the pin.
    volatile unsigned int* gpfsel = GPFSEL0 + index * 4;

    // Read the register.
    //const uint32_t value = mem_read32(gpfsel);
    r = *gpfsel;

    // Set the desired function for the pin.
    const unsigned int masked = r & ~(7 << shift);
    const unsigned int fsel = masked | mode << shift;

    // Write the value back to the register.
    //mem_write32(gpfsel, fsel);
    *gpfsel = fsel;
}

void gpio_set(const unsigned pin, const int high) {
    // The register index starting at GPSET0 or GPCLR0.
    unsigned int index = pin >> 5;
    // The bit in the registers to set or clear the pin.
    unsigned int bit = (1) << (pin & 31);
    if (high) {
        // Write the bit to GPSEL to set the pin high.
        //mem_write32(GPSET0 + index * 4, bit);
        *((volatile unsigned int*)(GPSET0 + index)) = bit;
    }
    else {
        // Write the bit to GPCLR to set the pin low.
        //mem_write32(BASE_ADDR + GPCLR0 + index * 4, bit);
        *((volatile unsigned int*)(GPCLR0 + index)) = bit;
    }
}