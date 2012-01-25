all : activists carnival

carnival:
	gcc -o carnival.out carnival-problem/carnival.c -O2 -Wall

activists:
	gcc -o activists.out activists-problem/activists.c -O2 -Wall

.PHONY: clean

clean:
	rm carnival.out
	rm activists.out

testCarnival: carnival
	time ./carnival.out < carnival-problem/testcases-carnival/input${TEST}.txt   
	@cat carnival-problem/testcases-carnival/output${TEST}.txt


testActivists: activists
	time ./activists.out < activists-problem/testcases-activists/input${TEST}.txt                   
	@cat activists-problem/testcases-activists/output${TEST}.txt