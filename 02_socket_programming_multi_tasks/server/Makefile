.PHONY: all debug clean

CC=g++
CFLAGS=
LFLAGS=-pthread

SRCS:=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)
BIN:=serverApp.out

all: $(BIN)

debug: CFLAGS+=-g
debug: LFLAGS+=-g
debug: $(BIN)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

clean:
	@echo "Cleaning up..."
	@rm -rvf *.o $(BIN)
