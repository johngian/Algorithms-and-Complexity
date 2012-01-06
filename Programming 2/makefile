all : xmasshopping teleport

teleport:
	gcc -o teleport.out teleport-problem/teleport.c -O2 -Wall

xmasshopping:
	gcc -o xmas.out xmasshopping-problem/xmasshopping.c -O2 -Wall

.PHONY: clean

clean:
	rm teleport.out
	rm xmas.out

testTeleport: teleport
	time ./teleport.out < teleport-problem/testcases-teleport/input${TEST}.txt   
	@cat teleport-problem/testcases-teleport/output${TEST}.txt


testXmasshopping: xmasshopping
	time ./xmas.out < xmasshopping-problem/testcases-xmas/input${TEST}.txt                   
	@cat xmasshopping-problem/testcases-xmas/output${TEST}.txt