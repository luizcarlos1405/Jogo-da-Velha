CSRC = $(wildcard *.c)

jogodavelha:   $(CSRC:.c=.o)
	@echo Creating executable.
	@gcc -o $@ $^ -lncurses
	@echo Done.

%.o:	%.c
	@echo Compiling object files: $@
	@gcc -c $< -lncurses
	@echo Done.

clean:
	@echo Removing object files.
	@rm *.o *.d
	@echo Done.

remade:
	@echo Recompiling.
	@$(MAKE) clean
	@$(MAKE)
	@echo Done.

install:
	@echo Installing.
	@cp ./jogodavelha /usr/local/bin
	@echo Done.

remove:
	@echo Removing.
	@rm /usr/local/bin/jogodavelha
	@echo Done.

-include $(CSRC:.c=.d)

%.d:	%.c
	@gcc $< -MM -MT '$*.o $*.d' -MD
