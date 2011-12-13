all: vacation books

vacation:
	gcc -o vacation.out vacation-problem/vacation.c

books:
	gcc -o books.out books-problem/books.c

.PHONY: clean 

clean:
	rm books.out
	rm vacation.out

testVacation: vacation
	./vacation.out < vacation-problem/testcases-vacation/input${TEST}.txt
	@cat vacation-problem/testcases-vacation/output${TEST}.txt

testBooks: books
	./books.out < books-problem/testcases-books/input${TEST}.txt
	@cat books-problem/testcases-books/output${TEST}.txt