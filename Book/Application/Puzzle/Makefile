CFLAGS = -g -Wall -Wshadow 
GCC = gcc $(CFLAGS)
LIBS = -lm # math library for sqrt
SRCS = main.c puzzle.c utility.c tree.c
TARGET = puzzle
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) -o $@ $(LIBS)

.c.o: 
	$(GCC) -c $*.c 

test: $(TARGET)
	/bin/rm -f -r outputs
	mkdir outputs
	./$(TARGET) 1 123456789ABCDEF- LL        > outputs/output11
	./$(TARGET) 1 123456789A-BDEFC LUDRL     > outputs/output12
	./$(TARGET) 1 123456789A-BDEFC UURDLULR  > outputs/output13
	./$(TARGET) 1 123456789A-BDEFC LRLRUD    > outputs/output14
	./$(TARGET) 1 123456789A-BDEFC UDRLUR    > outputs/output15
	./$(TARGET) 1 123456789A-BDEFC UUUUU     > outputs/output16
	./$(TARGET) 1 12-856439A7BDEFC DRUDLUDLR > outputs/output17
	./$(TARGET) 1 123- UL                    > outputs/output18
	./$(TARGET) 1 123456789ABCDEFGHIJKLMNO- LLLUURUDLRR > outputs/output19
	$(VALGRIND)=valgrindlog11 ./$(TARGET) 1 123- UL > /dev/null
	./$(TARGET) 2 123456789ABCDEF- 1          > outputs/output21
	./$(TARGET) 2 123456789ABCDEFGHIJKLMNO- 2 > outputs/output22
	./$(TARGET) 2 123456789ABCDEFGHIJKLMNO- 5 > outputs/output23
	./$(TARGET) 2 123- 4                      > outputs/output24
	$(VALGRIND)=valgrindlog2 ./$(TARGET) 2 123- 3 > /dev/null
	./$(TARGET) 3 123456789ABCDEF- 3          > outputs/output31
	./$(TARGET) 3 123456789ABCDE-F 3          > outputs/output32
	./$(TARGET) 3 123456789ABCDEFGHIJKLMNO- 2 > outputs/output33
	./$(TARGET) 3 12-3 4                      > outputs/output34
	./$(TARGET) 3 1-32 4                      > outputs/output35
	./$(TARGET) 3 123456789ABCDEFGHIJKLMN-O 6 > outputs/output36
	./$(TARGET) 3 12345678-ABCD9FGHIEJLMNOK 6 > outputs/output37
	$(VALGRIND)=valgrindlog31 ./$(TARGET) 3 12-3 5 > /dev/null
	$(VALGRIND)=valgrindlog32 ./$(TARGET) 3 123456789ABCDEFGHIJKLMN-O 6 > /dev/null

clean:
	rm -f *.o a.out $(TARGET) *log outputs/* valgrindlog*

