BINNAME = niobium
SRC = $(wildcard src/*.c)
CFLAGS = -std=gnu11 -Wall -lm -lpthread -lao -lsndfile -lasound

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

run:
	./$(BINNAME)

seq:
	$(CC) -o seq src/seq.c -std=gnu11 -Wall

clean:
	rm $(BINNAME)
