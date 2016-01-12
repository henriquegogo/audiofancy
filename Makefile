ALL:
	gcc -o main main.c -lSDL2 -lSDL2_mixer && ./main

clean:
	rm main
