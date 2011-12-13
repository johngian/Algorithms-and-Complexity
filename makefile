all: vacation books

vacation:
	gcc -o vacation vacation.c

books:
	gcc -o books books.c

.PHONY: clean 

clean:
	rm books
	rm vacation

testVacation: vacation
	./vacation < testcases-vacations/input${TEST}.txt
	@cat testcases-vacations/output${TEST}.txt
testBooks: books
	./books < testcases-books/input${TEST}.txt
	@cat testcases-books/output${TEST}.txt