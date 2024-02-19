CC = gcc
CFLAGS=-c -g
SRCS=$(wildcard *.c)
INCLUDES=$(wildcard *.h)
OBJS=$(SRCS:.c=.o)

main.exe: $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJS) : %.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean:
	del *.o *.exe

 

