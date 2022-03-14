#include "uart.h"
#include "gpio.h"
#include "str.h"

void led_init(void){
    gpio_select(47, GPIO_OUTPUT);
}

void light_led(){
    int test = 1000000;
    
    gpio_set(47, 0);

    do{asm volatile("nop");}while(test--);
    test = 1000000;

    gpio_set(47, 1);
    
    do{asm volatile("nop");}while(test--);
    test = 1000000;
}

void main()
{
    char input[100];
    // set up serial console and GPIO LED
    uart_init();
    gpio_select(23, GPIO_OUTPUT); // init led
    while(1){
		my_strset(input, 0, 100);
		uart_readline(input, 100);
        gpio_set(23, 1);
        if(my_strcmp(input, "myspecialpasswordhaha", my_strlen(input)) == 0){
            uart_puts("pass");
        }
        gpio_set(23, 0);
	}
}