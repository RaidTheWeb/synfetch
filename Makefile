OSCC ?= ~/.local/bin/x86_64-synnixos-gcc
SYSUSR ?= ~/SynnixOS/sysroot/usr

CC ?= gcc -std=gnu99
CFLAGS ?= -g -static
LDFLAGS ?= -g -static

PROGRAM ?= synfetch
ARGS ?=

local:
	@$(CC) $(CFLAGS) -o $(PROGRAM) $(PROGRAM).c
	@./$(PROGRAM) $(ARGS)

snx:
	@$(OSCC) $(CFLAGS) -o $(PROGRAM) $(PROGRAM).c
	@cp $(PROGRAM) $(SYSUSR)/bin/$(PROGRAM)