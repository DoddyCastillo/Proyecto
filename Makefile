wordfreq: main.o archivo.o
	gcc -o wordfreq main.o archivo.o $(DFLAGS)

# Compila usando la opción -g para facilitar la depuración con gdb.
.PHONY: debug
debug: DFLAGS = -g
debug: clean wordfreq

# Compila habilitando la herramienta AddressSanitizer para
# facilitar la depuración en tiempo de ejecución.
.PHONY: sanitize
sanitize: DFLAGS = -fsanitize=address,undefined
sanitize: clean wordfreq

archivo.o: archivo.c archivo.h
	gcc -c archivo.c $(DFLAGS)

main.o: main.c archivo.h
	gcc -c main.c $(DFLAGS)

.PHONY: clean
clean:
	rm -rf wordfreq *.o
