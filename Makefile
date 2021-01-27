#https://stackoverflow.com/questions/50329451/ifdef-and-conditional-compilation-with-makefile

OBFUSCATE=1
FLAGS=""

ifeq ($(OBFUSCATE),1)
  FLAGS=-DOBFUSCATE=1
else
  #
endif
BCC=bcc $(FLAGS)
YASM=yasm $(FLAGS)

all: disk.fd

disk.fd: boot.bin kernel.bin
	python3 packer_bootloader.py boot.bin obfuscated_bootloader.bin
	python3 packer_kernel.py kernel.bin obfuscated_kernel.bin
		
        ifeq ($(OBFUSCATE),1)
	    cat obfuscated_bootloader.bin obfuscated_kernel.bin > disk.fd
        else
	    cat boot.bin kernel.bin > disk.fd
        endif
	echo -e 'endstream\nendobj\n'>>disk.fd
	#Add an extra block to ensure none are non-filled.
	#dd if=/dev/zero  bs=512 count=1 >>disk.fd
kernel.bin: kernel.c
	python3 packer_strings.py flags.h obfuscated_flags.h
	$(BCC) -0 -c kernel.c 
	$(BCC) -0 -c screen.c
	$(BCC) -0 -c keyboard.c
	$(BCC) -0 -c menu.c
	#$(BCC) -0 -c memory.c// memory.o
	$(BCC) -0 -c strings.c
	$(BCC) -0 -c interactions.c
	$(BCC) -0 -c aux.c
	$(BCC) -0 -c disk.c
	ld86 -0 -M -T 0x7e00 -d kernel.o menu.o screen.o keyboard.o strings.o interactions.o aux.o disk.o -o kernel.bin 
	
run: runqemu
runqemu: all
	qemu-system-i386 -fda disk.fd
runbochs: all
	bochs-bin -q 'boot:a' 'floppya: 1_44=disk.fd, status=inserted' 'display_library: sdl'
runbochsx: all
	bochs-bin -q 'boot:a' 'floppya: 1_44=disk.fd, status=inserted' 'display_library: x'

boot.bin: boot.s
	$(YASM) -f bin -o boot.bin boot.s 
	#hd boot.bin
clean:
	rm -f *.o *.bin *.fd
	rm -f obfuscated_flags.h
dis: kernel.bin
	rasm2 -o 0x7e00 -d -b 16 "`cat kernel.bin| hexdump -v -e '/1 "%02X "'`"
