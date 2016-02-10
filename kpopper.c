/*
* kpopper.c
*/
void kmain(void) {
	const char *str = "KERNEL POPPER v0.1 ~~ Welcome to the new age.";
	char *vidptr = (char*)0xb8000; //video mem begins here
	unsigned int i = 0, j = 0;

	/* this loop clears the screen. there are 25x80 elements, 2 bytes ea */
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - green on black screen */
		vidptr[j+1] = 0x02;
		j += 2;
	}

	j = 0;

	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: give character black bg and light grey fg */
		vidptr[i+1] = 0x02;
		j++;
		i += 2;
	}
	return;
}

