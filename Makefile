BINNAME = sampler
SRC = $(wildcard src/*.c)
CFLAGS = -std=c99 -Wall -lm -lao -lsndfile -lpthread

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

run:
	./$(BINNAME)

clean:
	rm $(BINNAME)
