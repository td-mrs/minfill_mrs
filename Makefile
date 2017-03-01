CC = g++ 
FLAGS = -Wall -O3 -std=c++11 -I.
FLOBJ = $(FLAGS) -c
FLEXE = $(FLAGS) -o $@ $^

TIE_BREAK_POLICY = neighbor_future_degree_tie_break_policy.o tie_break_policy.o
TRIANGULATION = $(TIE_BREAK_POLICY) triangulation.o tie_break_min_fill_triangulation.o
TREE_DECOMPOSITION = tree_decomposition.o tie_break_min_fill_triangulation_tree_decomposition.o triangulation_tree_decomposition.o

minfill_mrs: child_node.o cluster_node.o cluster_tree.o light_graph.o order.o  timer.o vertex_set.o $(TRIANGULATION) $(TREE_DECOMPOSITION) main.cpp
	$(CC) $(FLEXE)

%.o: %.cpp %.h
	$(CC) $(FLOBJ) $<

clean:
	rm -f *.o
	rm -f minfill_mrs
