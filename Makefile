SOURCE=main.c list.c
FLAGS= -O3
EXEC=algo

all:
	clang $(FLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm $(EXEC)
