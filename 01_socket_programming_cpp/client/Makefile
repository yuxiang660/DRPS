.PHONY: all debug clean

CC=g++
CFLAGS=
LFLAGS=

SRCS:=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)
BIN:=clientApp.out

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
