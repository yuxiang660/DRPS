.PHONY: all debug clean

CC=g++
CFLAGS=
LFLAGS=

OBJ_DIR=./objects

SRCS:=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
BIN:=serverApp.out

all: $(BIN)

debug: CFLAGS+=-g
debug: LFLAGS+=-g
debug: $(BIN)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

clean:
	@echo "Cleaning up..."
	@rm -rvf *.o $(BIN) $(OBJ_DIR)
