libraryMaker: book.o library.o main.o
	g++ book.o library.o main.o -o libraryMaker
book.o: book.cpp book.h
	g++ -c book.cpp
library.o: library.cpp library.h book.h
	g++ -c library.cpp
main.o: main.cpp book.h library.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm libraryMaker
run: libraryMaker
	./libraryMaker
