.PHONY: all debug server client clean

CC=g++

all: client server

debug:
	$(MAKE) debug -C server
	$(MAKE) debug -C client

server:
	$(MAKE) -C server

client:
	$(MAKE) -C client

clean:
	$(MAKE) clean -C server
	$(MAKE) clean -C client
