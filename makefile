all:exec

exec: task3c.c
	gcc -g -m32 -c -o task3c.o task3c.c
	gcc -g -m32 task3c.o -o Menu
	rm task3c.o

.PHONY: clean
clean:
	rm -rf ./*.o Menu

