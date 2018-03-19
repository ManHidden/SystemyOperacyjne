CFLAGS = -g -O -Wall
LIBS = -lm
DIR = `basename $(PWD)`

OBJ =\
	main.c \
	proc_id.c

OBJ2 = \
	proc_fork.c

OBJ3 =\
	proc_exec.c

all: id fork exec

clean:
	rm -f *.o proc_fork
	rm -f *.o proc_exec
	rm -f *.o proc_id
	clear

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $<

id: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o proc_id
	clear
	./proc_id

fork: $(OBJ2)
	$(CC) $(OBJ2) $(LIBS) -o proc_fork
	clear
	./proc_fork

exec: $(OBJ3)
	$(CC) $(OBJ3) $(LIBS) -o proc_exec
	clear
	./proc_exec

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
