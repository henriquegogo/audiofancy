BINNAME = niobium
SRC = $(wildcard src/*.c)
CFLAGS = -std=gnu11 -Wall -lm -lSDL2 -lSDL2_mixer

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

debug:
	$(CC) -g -o $(BINNAME) $(SRC) $(CFLAGS)
	gdb $(BINNAME)

run:
	./$(BINNAME)

clean:
	rm $(BINNAME)
