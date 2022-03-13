#include "gpio.h"

#define TIMER_BASE (MMIO_BASE+0x00003000)
#define TIMER_CS   ((volatile unsigned int*)(TIMER_BASE+0x00))
#define TIMER_CLO  ((volatile unsigned int*)(TIMER_BASE+0x04))
#define TIMER_CHI  ((volatile unsigned int*)(TIMER_BASE+0x08))
#define TIMER_C0   ((volatile unsigned int*)(TIMER_BASE+0x0c))
#define TIMER_C1   ((volatile unsigned int*)(TIMER_BASE+0x10))
#define TIMER_C2   ((volatile unsigned int*)(TIMER_BASE+0x14))
#define TIMER_C3   ((volatile unsigned int*)(TIMER_BASE+0x18))

unsigned int timer_high(void) {
  return *TIMER_CHI;
}

unsigned int timer_low(void) {
  return *TIMER_CLO;
}

unsigned long long timer(void) {
  unsigned int high, low;

  do {
    high = *TIMER_CHI;
    low = *TIMER_CLO;
  }
  while (*TIMER_CHI != high);
  
  return (unsigned long long)high << 32 | low;
}

void timer_wait_until(const unsigned long long t1) {
  while (timer() < t1) {
    // Empty.
  }
}