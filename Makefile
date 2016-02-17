CSRC = $(wildcard *.c)

jogodavelha:   $(CSRC:.c=.o)
	@echo Criando executável.
	@gcc -o $@ $^
	@echo Feito.

%.o:	%.c
	@echo Compilando arquivo objeto: $@
	@gcc -c $<
	@echo Feito.

clean:
	@echo removendo arquivos objetos.
	@rm *.o *.d
	@echo Feito.

remade:
	@echo Recompilando.
	@$(MAKE) clean
	@$(MAKE)
	@echo Feito.

install:
	@echo Instalando.
	@cp ./jogodavelha /usr/local/bin
	@echo Feito.

remove:
	@echo Removendo.
	@rm /usr/local/bin/jogodavelha
	@echo Feito.

-include $(CSRC:.c=.d)

%.d:	%.c
	@gcc $< -MM -MT '$*.o $*.d' -MD
