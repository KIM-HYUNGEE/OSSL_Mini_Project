miniProject: main.o base.o extras.o
	gcc main.o base.o extras.o -o miniProject

main.o: main.c 
	gcc -c main.c -o main.o

base.o: base.c base.h record.h save.log
	gcc -c base.c -o base.o

extras.o: extras.c extras.h record.h save.log
	gcc -c extras.c -o extras.o

clean:
	rm miniProject main.o base.o extras.o

