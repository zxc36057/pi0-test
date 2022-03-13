
This is a Bare Metal test for reapberry pi zero W.
This project is modified base on [bztsrc/raspi3-tutorial](https://github.com/bztsrc/raspi3-tutorial) and [leiradel/barebones-rpi](https://github.com/leiradel/barebones-rpi).
Base on raspi3-tutorial 05_uart0, I add gpio_select and gpio_set functions form barebones-rpi.
Also change the MMIO_BASE address to 0x20000000 for pi 0.
To avoid changing SD card frequently, I also add the bootloader folder which is from raspi3-tutorial/14_raspbootin64.
And I add the auto_script.py that a python script which is use for send the kernel.img file to pi0.
Commnd for auto_script.py : ```sudo python3 auto_script.py kernel.img``` 
The command above will read kernel.img file and calculate the size of kernel.img, then send to pi0 by UART.
I recommand use the gcc-arm-none-eabi to compile this project.
(sudo apt install gcc-arm-none-eabi)




