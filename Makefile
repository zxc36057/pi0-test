ARMGNU ?= arm-none-eabi
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all: clean kernel.img

start.o: start.S
	$(ARMGNU)-gcc $(CFLAGS) -c start.S -o start.o

%.o: %.c
	$(ARMGNU)-gcc $(CFLAGS) -c $< -o $@

kernel.img: start.o $(OBJS)
	$(ARMGNU)-ld -nostdlib start.o $(OBJS) -T link.ld -o kernel.elf
	$(ARMGNU)-objcopy -O binary kernel.elf kernel.img

clean:
	rm kernel.elf *.o >/dev/null 2>/dev/null || true
