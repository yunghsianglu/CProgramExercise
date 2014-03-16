CFLAGS = -g -Wall -Wshadow 
GCC = gcc $(CFLAGS)
LIBS = -lm
SRCS = main.c bmpfile.c bmpinvert.c bmpcolor.c bmpedge.c bmpequalize.c bmpgray.c
TARGET = image
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) -o $@ $(LIBS)

.c.o: 
	$(GCC) -c $*.c 

test: $(TARGET)
	rm -f -r outputs
	mkdir outputs
	./image inputs/colorchecker.bmp red outputs/checkerred.bmp
	./image inputs/colorchecker.bmp green outputs/checkergreen.bmp
	./image inputs/colorchecker.bmp blue outputs/checkerblue.bmp
	./image inputs/colorchecker.bmp invert outputs/checkinvert.bmp
	./image inputs/eg1.bmp invert outputs/eg1invert.bmp
	./image inputs/eg1.bmp gray outputs/eg1gray.bmp
	./image inputs/eg2.bmp red outputs/eg2red.bmp
	./image inputs/eg2.bmp gray outputs/eg2gray.bmp
	./image inputs/eg3.bmp blue outputs/eg3blue.bmp
	./image inputs/eg3.bmp edge outputs/eg3edge.bmp
	./image inputs/eg4.bmp green outputs/eg4green.bmp
	./image inputs/eg5.bmp edge outputs/eg5edge.bmp
	./image inputs/eg6.bmp equalize outputs/eg6equal.bmp
	./image inputs/eg7.bmp equalize outputs/eg7equal.bmp
	./image inputs/eg8.bmp equalize outputs/eg8equal.bmp
	./image inputs/eg9.bmp equalize outputs/eg9equal.bmp

clean:
	rm -f *.o a.out $(TARGET) *log outputs/*
