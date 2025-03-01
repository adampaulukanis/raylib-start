CC=egcc
CFLAGS=-g -Wall -Wextra -Werror -lm -I"/usr/local/include" -L"/usr/local/lib" -lraylib

all: minimal first gameScreen move-ball \
	textures

gameScreen: gameScreen.c

first: first.c

move-ball: move-ball.c

minimal: minimal.c

textures: textures.c

clean:
	rm -rf *.core a.out first gameScreen move-ball
	rm -rf minimal
	rm -rf textures
