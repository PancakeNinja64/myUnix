CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c parser.c executor.c
OBJS =$(SRCS:.c=.o)
TARGET = myUnix

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)