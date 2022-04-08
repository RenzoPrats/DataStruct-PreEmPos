CFLAGS= -Wall -Werror

all: cliente

cliente: cliente.c arvore.o 
	gcc $^ -o $@

%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o cliente