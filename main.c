#include "uart.h"
#include "mbox.h"
#include "gpio.h"
#include "timer.h"
#include "str.h"

void led_init(void){
    gpio_select(47, GPIO_OUTPUT);
}

void help()
{
	uart_puts("help : help\n");
	uart_puts("hello : print Hello World!\n");
	uart_puts("timestamp : get current timestamp\n");
	uart_puts("reboot : reboot system\n");
	uart_puts("vcb : VC Core base address.\n");
	uart_puts("brv : board revision.\n");
	uart_puts("lfb : frame buffer.\n");
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

int password() {
    const char pass[] = "pass\n";
    char input[100];
    int i=0;
    my_strset(input, 0, 100);
    uart_puts("Please enter password : ");
    uart_readline(input, 100);
    for(i=0;i<5;i++){
        if(input[i] != pass[i]){
            break;
        }
    }
    if(i==4) return 1;
    return 0;
}


void main()
{
    char *command[5] = {"help", "hello", "led", "password", 0};
	//uart_hex((unsigned int)command);
    char input[100];
    // set up serial console and GPIO LED
    uart_init();
    led_init();
    
    uart_puts("Hello~~ try 'help' \n");
	
	
    while(1){
		my_strset(input, 0, 100);
		uart_puts(">> ");
		uart_readline(input, 100);
		if(my_strcmp(input, command[0], my_strlen(input)) == 0) //b *0x20af8  (0x20aec:     add     x1, x20, #0xde8)
        {	
			help();
        }
        else if(my_strcmp(input, command[1], my_strlen(input)) == 0)
        {
            uart_puts("Hello World!\n");
        }
		else if(my_strcmp(input, command[2], my_strlen(input)) == 0)
		{
			light_led();
		}
        else if(my_strcmp(input, command[3], my_strlen(input)) == 0)
        {
            if(password()){
                light_led();
            }
        }
		else
		{
			uart_puts("Err command ");
			uart_puts(input);
			uart_puts(" not found, try <help>");
			uart_puts("\n");
		}
	}
}
