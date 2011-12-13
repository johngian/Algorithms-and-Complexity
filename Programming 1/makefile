all: vacation books

vacation:
	gcc -o vacation vacation/vacation.c

books:
	gcc -o books books/books.c

.PHONY: clean 

clean:
	rm books
	rm vacation

testVacation: vacation
	./vacation < vacation/testcases-vacation/input${TEST}.txt
	@cat vacation/testcases-vacation/output${TEST}.txt

testBooks: books
	./books < books/testcases-books/input${TEST}.txt
	@cat books/testcases-books/output${TEST}.txt