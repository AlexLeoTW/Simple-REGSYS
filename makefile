OBJS = main.o init.o load.o grpinsert.o search.o suspend.o calavg.o\
 printAll.o printInd.o

PROGNAME = REGSYS

run: $(OBJS)
	gcc $(OBJS) -o $(PROGNAME)

main.o: main.c
	gcc -c main.c

init.o: init.c
	gcc -c init.c

load.o: load.c
	gcc -c load.c

grpinsert.o: grpinsert.c
	gcc -c grpinsert.c

search.o: search.c
	gcc -c search.c

suspend.o: suspend.c
	gcc -c suspend.c

calavg.o: calavg.c
	gcc -c calavg.c

printAll.o: printAll.c
	gcc -c printAll.c

printInd.o: printInd.c
	gcc -c printInd.c

clean:
	rm $(OBJS)
	rm $(PROGNAME)

