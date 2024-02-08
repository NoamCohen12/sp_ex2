
all: my_graph my_Knapsack

.PHONY: all clean
	
my_graph: libmymath.a my_graph.o
	gcc -Wall -g my_graph.o ./libmymath.a -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -g -c  my_graph.c -o my_graph.o



libmymath.a: my_mat.o 
	ar rcs libmymath.a my_mat.o
	ranlib libmymath.a


my_mat.o: my_mat.c my_mat.h
	gcc -Wall -g -fPIC -c my_mat.c -o my_mat.o

my_Knapsack: my_Knapsack.c  
	gcc -Wall -g my_Knapsack.c -o my_Knapsack	


clean:
	rm -f *.o *.a my_graph my_Knapsack





















