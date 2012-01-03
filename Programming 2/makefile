all : teleport xmasshopping

teleport:
	gcc -o teleport.out teleport-problem/teleport.c -O2 -Wall

xmasshopping:
	gcc -o xmas.out xmasshopping-problem/xmasshopping.c -O2 -Wall

.PHONY: clean

clean:
	rm teleport.out
	rm xmas.out