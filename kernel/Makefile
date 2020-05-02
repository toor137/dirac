KERNEL=dirac
KERNEL_ELF=$(KERNEL).elf

CC = x86_64-elf-gcc
AS = nasm

CHARDFLAGS = -std=gnu99 -masm=intel \
    -mno-sse \
    -mno-sse2 \
    -mno-red-zone \
	-mcmodel=kernel \
    -nostdlib \
    -ffreestanding \
    -I.
NASMFORMAT = elf64

CFILES    := $(shell find . -type f -name '*.c')
ASMFILES  := $(shell find . -type f -name '*.asm')
REALFILES := $(shell find . -type f -name '*.real')
BINS      := $(REALFILES:.real=.bin)
OBJ       := $(CFILES:.c=.o) $(ASMFILES:.asm=.o)

CLINKFLAGS= -nostdlib \
	-static-libgcc -lgcc \
	-T ./linker.ld

CLAGS = -O2 -Wall -Wextra

$(KERNEL_ELF): $(BINS) $(OBJ) $(H_FILES)
	$(CC) $(OBJ) $(CLINKFLAGS) -o $@

%.o: %.c
	$(CC) $(CHARDFLAGS) $(CFLAGS) -c $< -o $@

%.bin: %.real
	$(AS) $< -f bin -o $@

%.o: %.asm
	$(AS) $< -f $(NASMFORMAT) -o $@

clean:
	rm -f $(OBJ) $(BINS) kernel.bin
