ch0.exe:main.o set.o new.o object.o
	gcc -o ch0.exe main.o set.o new.o object.o

main.o:main.c set.h
	gcc -c main.c

set.o:set.c set.h
	gcc -c set.c

new.o:new.c new.h
	gcc -c new.c

object.o:object.c object.h
	gcc -c object.c

.PHONY:run clean
run:
	./ch0.exe

clean:
	-rm -f main.o set.o new.o object.o ch0.exe

