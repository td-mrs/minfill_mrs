/// \file 
/// \brief Definitions related to the Min_Fill_Triangulation_Tree_Decomposition class

#ifndef TIE_BREAK_MIN_FILL_TRIANGULATION_TREE_DECOMPOSITION_H
#define TIE_BREAK_MIN_FILL_TRIANGULATION_TREE_DECOMPOSITION_H

#include "triangulation_tree_decomposition.h"
#include "tie_break_policy.h"


class Tie_Break_Min_Fill_Triangulation_Tree_Decomposition : public Triangulation_Tree_Decomposition   /// This class allows to compute a tree-decomposition from a triangulation obtained by applying the Min-Fill algorithm and breaking ties thanks to a given policy
{
	public:
		// constructors and destructor
		Tie_Break_Min_Fill_Triangulation_Tree_Decomposition (Light_Graph * gs, Tie_Break_Policy * tbp);	///< constructs a tree-decomposition related to the graphical structure gs and the policy tbp for breaking ties during Min-Fill
		~Tie_Break_Min_Fill_Triangulation_Tree_Decomposition ();																								///< destructor
};

#endif

