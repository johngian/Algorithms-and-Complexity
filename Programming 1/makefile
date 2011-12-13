all: vacation books

vacation:
	gcc -o vacation vacation-problem/vacation.c

books:
	gcc -o books books-problem/books.c

.PHONY: clean 

clean:
	rm books
	rm vacation

testVacation: vacation
	./vacation < vacation-problem/testcases-vacation/input${TEST}.txt
	@cat vacation-problem/testcases-vacation/output${TEST}.txt

testBooks: books
	./books < books-problem/testcases-books/input${TEST}.txt
	@cat books-problem/testcases-books/output${TEST}.txt