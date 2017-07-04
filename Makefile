BINNAME = niobium
SRC = $(wildcard src/*.c)
CFLAGS = -std=gnu11 -Wall -lm -lpthread -lao -lsndfile -lasound

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

run:
	./$(BINNAME)

clean:
	rm $(BINNAME)
