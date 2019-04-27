# code details

EXE_DIR = .
EXE = $(EXE_DIR)/Library

SRC= main.c book.c student.c record.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c recordoperation.h studentoperation.h bookoperation.h librarystructure.h

student.o:  student.c recordoperation.h studentoperation.h bookoperation.h librarystructure.h

book.o: book.c recordoperation.h studentoperation.h bookoperation.h librarystructure.h

record.o: record.c recordoperation.h studentoperation.h bookoperation.h librarystructure.h

