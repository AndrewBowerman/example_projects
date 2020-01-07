heapOfStudents: address.o date.o student.o main.o
	g++ address.o date.o student.o main.o -o heapOfStudents
address.o: address.cpp address.h
	g++ -c address.cpp
date.o: date.cpp date.h
	g++ -c date.cpp
student.o: student.cpp student.h address.h date.h
	g++ -c student.cpp
main.o: main.cpp address.h date.h student.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm heapOfStudents
run: heapOfStudents
	./heapOfStudents
