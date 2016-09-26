
%.o: %.asm
	$(AS) -f elf64 $< -o $@

test_c: test.o sobel_c.o
	$(CC) -lm $^ -o $@

test_asm: test.o sobel_asm.o
	$(CC) $^ -o $@

%.s: %.c
	$(CC) -fno-asynchronous-unwind-tables -S $< -o $@