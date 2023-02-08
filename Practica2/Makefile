all: init getty myshell

init: init.c
	gcc -o init init.c

getty: getty.c
	gcc -o getty getty.c

myshell: myshell.c
	gcc -o myshell myshell.c

clean:
	rm init getty myshell