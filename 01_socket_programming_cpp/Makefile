.PHONY: all server client clean

CC=g++

all: client server

server:
	$(MAKE) -C server

client:
	$(MAKE) -C client

clean:
	$(MAKE) clean -C server
	$(MAKE) clean -C client
