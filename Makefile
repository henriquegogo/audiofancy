ALL:
	gcc -o main main.c -lSDL2 -lSDL2_mixer -lncurses && ./main

clean:
	rm main
