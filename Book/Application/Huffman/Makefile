CFLAGS = -g -Wall -Wshadow
GCC = gcc $(CFLAGS)
SRCS = main.c encode.c freq.c tree.c list.c utility.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file
TARGET = huffman

$(TARGET): $(OBJS) 
	$(GCC) $(OBJS) -o $(TARGET)

test1: $(TARGET)
	./$(TARGET) e input1 compress1
	$(VALGRIND)=logenc1 ./$(TARGET) e input1 compress1
	./$(TARGET) d compress1 output1
	$(VALGRIND)=logdec1 ./$(TARGET) d compress1 output1
	diff input1 output1

test2: $(TARGET)
	./$(TARGET) e input2 compress2
	$(VALGRIND)=logenc2 ./$(TARGET) e input2 compress2
	./$(TARGET) d compress2 output2
	$(VALGRIND)=logdec2 ./$(TARGET) d compress2 output2
	diff input2 output2

test3: $(TARGET)
	./$(TARGET) e input3 compress3
	$(VALGRIND)=logenc3 ./$(TARGET) e input3 compress3
	./$(TARGET) d compress3 output3
	$(VALGRIND)=logdec3 ./$(TARGET) d compress3 output3
	diff input3 output3

testUN: $(TARGET)
	./$(TARGET) e UNcharter UNcompress
	$(VALGRIND)=logencUN ./$(TARGET) e UNcharter UNcompress
	$(VALGRIND)=logdecUN ./$(TARGET) d UNcompress UNdecompress
	diff UNcharter UNdecompress

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o a.out $(TARGET) log* compress? output? UN*compress




