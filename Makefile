ALL:
	gcc -lSDL2 -lSDL2_mixer main.c -o main; ./main

clean:
	rm main
