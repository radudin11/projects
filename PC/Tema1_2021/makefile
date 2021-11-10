build: task1 task2

task1 : task1.o
	gcc -Wall task1.o -o task1 

task1.o : task1.c
	gcc -Wall -c task1.c

task2: task2.o
    gcc -Wall task2.o -o task2 

task2.o: task2.c
	gcc -Wall -c task2.c

clean:
    rm -rf *.o task1 task2