SOURCE=main.c list.c graph.c set.c
FLAGS= -O3
EXEC=algo

all:
	clang $(FLAGS) -o $(EXEC) $(SOURCE)

clean:
	rm $(EXEC)
	rm -r $(EXEC)*
