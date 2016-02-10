all:
	gcc -o main main.c -lSDL2 -lSDL2_mixer -lncurses && ./main

ao:
	gcc -o aoplayer aoplayer.c -lao -lsndfile -lpthread && ./aoplayer

clean:
	rm main
