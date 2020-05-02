CC = x86_64-elf-gcc
AS = nasm

CHARDFLAGS = -std=gnu99 -masm=intel \
    -mno-sse \
    -mno-sse2 \
    -mno-red-zone \
	-mcmodel=kernel \
    -nostdlib \
    -ffreestanding \
    -I./include/
NASMFORMAT = elf64

CFILES    := $(shell find . -type f -name '*.c')
ASMFILES  := $(shell find . -type f -name '*.asm')
REALFILES := $(shell find . -type f -name '*.real')
BINS      := $(REALFILES:.real=.bin)
OBJ       := $(CFILES:.c=.o) $(ASMFILES:.asm=.asm.o)

CLINKFLAGS= -nostdlib \
	-static-libgcc -lgcc \
	-T ./linker.ld

CLAGS = -O2 -Wall -Wextra

kernel.bin: $(BINS) $(OBJ) $(H_FILES)
	$(CC) $(OBJ) $(CLINKFLAGS) -o $@

%.o: %.c
	$(CC) $(CHARDFLAGS) $(CFLAGS) -c $< -o $@

%.bin: %.real
	$(ASM) $< -f bin -o $@

%.o: %.asm
	$(ASM) $< -f $(NASMFORMAT) -o $@

clean:
	rm -f $(OBJ) $(BINS) kernel.bin
