CFLAGS = -g -O
LIBS = -lm

OBJ =\
	main.c \
	proc_id.c \
	proc_fork.c

OBJ2 =\
	proc_exec.c

all: fork exec

clean:
	rm -f *.o proc_fork
	rm -f *.o proc_exec
	clear

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $<

fork: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o proc_fork
	clear
	./proc_fork

exec: $(OBJ2)
	$(CC) $(OBJ2) $(LIBS) -o proc_exec
	clear
	./proc_exec

