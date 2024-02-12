
all: my_graph my_Knapsack my_mat.a

.PHONY: all clean
	
my_graph: my_mat.a my_graph.o
	gcc -Wall -g my_graph.o ./my_mat.a -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -g -c  my_graph.c -o my_graph.o


my_mat.a: my_mat.o 
	ar rcs my_mat.a my_mat.o
	ranlib my_mat.a


my_mat.o: my_mat.c my_mat.h
	gcc -Wall -g -fPIC -c my_mat.c -o my_mat.o

my_Knapsack: my_Knapsack.c  
	gcc -Wall -g my_Knapsack.c -o my_Knapsack	


clean:
	rm -f *.o *.a my_graph my_Knapsack





















