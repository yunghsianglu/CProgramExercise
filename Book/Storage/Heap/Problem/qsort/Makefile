GCC = gcc
CFLAGS = -g -Wall -Wshadow 
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --log-file=

mysort: main.c
	$(GCC) $(CFLAGS) main.c -o $@

clean:
	/bin/rm -f input* expected* *.o output* mysort valgrindlog*


