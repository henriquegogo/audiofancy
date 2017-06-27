BINNAME = sampler
SRC = $(wildcard src/*.c)
CFLAGS = -std=gnu11 -Wall -lm -lao -lsndfile -lpthread

all:
	$(CC) -o $(BINNAME) $(SRC) $(CFLAGS)

run:
	./$(BINNAME)

clean:
	rm $(BINNAME)
