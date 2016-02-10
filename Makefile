all: kpopper

kpopper: kasm.o kc.o
	ld -m elf_i386 -T link.ld -o kpopper kasm.o kc.o

kasm.o: kpopper.asm
	nasm -f elf32 kpopper.asm -o kasm.o

kc.o: kpopper.c
	gcc -m32 -c kpopper.c -o kc.o

clean:
	rm -f *.o kpopper
