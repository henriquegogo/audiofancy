BINNAME = niobium
SRC = $(wildcard src/*.c)
CFLAGS = -std=gnu11 -Wall -lm -lpthread -lao -lsndfile -lasound

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

debug:
	$(CC) -g -o $(BINNAME) $(SRC) $(CFLAGS)
	gdb $(BINNAME)

run:
	./$(BINNAME)

clean:
	rm $(BINNAME)
