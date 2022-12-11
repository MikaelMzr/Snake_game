CC = gcc

CFLAGS = -ansi -pedantic -Wall

LDFLAGS = -lncurses

EXEC = serpent

SRC =	main.c \
		graphique.c \
		monde.c \
		menu.c \
		pomme.c \
                case.c \
		serpent.c \

HEADER = include/

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

SRC_PATH = $(shell find src -type d)

vpath %.c $(foreach rep, $(SRC_PATH), $(rep):)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)main.o : $(HEADER)monde.h $(HEADER)pomme.h $(HEADER)menu.h

$(OBJ_PATH)graphique.o : $(HEADER)graphique.h $(HEADER)pomme.h $(HEADER)serpent.h $(HEADER)monde.h

$(OBJ_PATH)monde.o : $(HEADER)monde.h $(HEADER)serpent.h $(HEADER)pomme.h $(HEADER)graphique.h $(HEADER)menu.h

$(OBJ_PATH)pomme.o : $(HEADER)pomme.h $(HEADER)case.h

$(OBJ_PATH)serpent.o : $(HEADER)case.h $(HEADER)serpent.h

$(OBJ_PATH)case.o : $(HEADER)case.h

$(OBJ_PATH)menu.o : $(HEADER)monde.h $(HEADER)menu.h

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)

clean :
	/bin/rm -f $(OBJ)

mrproper : clean
	/bin/rm -f $(EXEC)

install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
