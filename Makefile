CC=cc
CFLAGS=-g -Wall -Wextra -Werror -lm -I"/usr/local/include" -L"/usr/local/lib" -lraylib

all: minimal first gameScreen move-ball \
	textures play1 player_big \
	x1

gameScreen: gameScreen.c

first: first.c

move-ball: move-ball.c

minimal: minimal.c

textures: textures.c

play1: play1.c

player_big: player_big.c

x1: x1.c

clean:
	rm -rf *.core a.out first
	rm -rf gameScreen move-ball
	rm -rf minimal
	rm -rf textures play1 player_big
	rm -rf x1
