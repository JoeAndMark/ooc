ch2.exe:main.o new.o mystring.o
	-gcc -o ch2.exe main.o new.o mystring.o

main.o:main.c new.h mystring.h
	-gcc -c main.c

new.o:new.c new.h
	-gcc -c new.c

mystring.o:mystring.c mystring.h
	-gcc -c mystring.c

.PHONY:run clean
run:
	-./ch2.exe

clean:
	-rm -f ch2.exe main.o mystring.o set.o new.o

