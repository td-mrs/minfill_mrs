#include "tie_break_min_fill_triangulation_tree_decomposition.h"
#include "tie_break_min_fill_triangulation.h"
#include <iostream>

//-----------------------------
// constructors and destructor
//-----------------------------


Tie_Break_Min_Fill_Triangulation_Tree_Decomposition::Tie_Break_Min_Fill_Triangulation_Tree_Decomposition (Light_Graph * gs, Tie_Break_Policy * tbp) : Triangulation_Tree_Decomposition (gs)
// constructs a tree-decomposition related to the graphical structure gs and the policy tbp for breaking ties during Min-Fill
{
	T = new Tie_Break_Min_Fill_Triangulation (g,tbp);

	Make_Tree (T->Clique_List());
}


Tie_Break_Min_Fill_Triangulation_Tree_Decomposition::~Tie_Break_Min_Fill_Triangulation_Tree_Decomposition ()
// destructor
{
}
