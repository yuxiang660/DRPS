.PHONY: all clean

CC=g++
CFLAGS=
LFLAGS=

SRCS:=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)
BIN:=clientApp.out

all: $(BIN)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN): $(OBJS)
	$(CC) $(LFAGS) $^ -o $@

clean:
	@echo "Cleaning up..."
	@rm -rvf *.o $(BIN)
