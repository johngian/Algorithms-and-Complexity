all: vacation books-binary books-dynamic

vacation:
	gcc -o vacation.out vacation-problem/vacation.c -O2 -Wall

books-dynamic:
	gcc -o books-dynamic.out books-problem/books-dynamic.c -O2 -Wall

books-binary:
	gcc -o books-binary.out books-problem/books-binary.c -O2 -Wall

.PHONY: clean 

clean:
	rm books-binary.out
	rm books-dynamic.out
	rm vacation.out

testVacation: vacation
	./vacation.out < vacation-problem/testcases-vacation/input${TEST}.txt
	@cat vacation-problem/testcases-vacation/output${TEST}.txt

testBooks: books-binary
	./books-binary.out < books-problem/testcases-books/input${TEST}.txt
	@cat books-problem/testcases-books/output${TEST}.txt