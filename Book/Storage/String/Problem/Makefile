GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = mystring.o main.o
HDRS = mystring.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --log-file=

mystring: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f mystring $(OBJS) output* memoutput*

testall: test0 test1 test2

test0: mystring
	$(VALGRIND)memoutput0 ./mystring strlen input output_strlen
	diff -q output_strlen expected_strlen

test1: mystring
	$(VALGRIND)memoutput1 ./mystring countchar input output_countchar
	diff -q output_countchar expected_countchar

test2: mystring
	$(VALGRIND)memoutput2 ./mystring strupper input output_strupper
	diff -q output_strupper expected_strupper
