
SRC1 = GuessASong.c
SRC2 = GameLib.c
SRC3 = FileLib.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

EXE = $(SRC1:.c=.e)
hfile = GameLib.h FileLib.h
Flag = -g
all	: $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3)
	gcc $(Flag) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE)

$(OBJ1): $(SRC1) $(hfile)
	gcc -c $(Flag) $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC2) $(hfile)
	gcc -c $(Flag) $(SRC2) -o $(OBJ2)

$(OBJ3): $(SRC3) $(hfile)
	gcc -c $(Flag) $(SRC3) -o $(OBJ3)