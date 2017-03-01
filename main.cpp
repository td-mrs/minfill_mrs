#include <iostream>
#include "tree_decomposition.h"
#include "tie_break_min_fill_triangulation_tree_decomposition.h"
#include "timer.h"

#include <fstream>
#include <light_stack.h>

#include "neighbor_future_degree_tie_break_policy.h"

using namespace std;

int main (int argc, char ** argv)
{
	Light_Graph * gs = 0;
	Tree_Decomposition * TD = 0;
	
 	try
 	{
    gs = new Light_Graph;
		
		gs->Load_TW (argv[argc-1]);
		
		TD = new Tie_Break_Min_Fill_Triangulation_Tree_Decomposition (gs,new Neighbor_Future_Degree_Tie_Break_Policy(gs->N()));


		// printing of the selected information (if any)

    cout << "s td " << TD->Nb_Clusters() << " " << TD->Get_W()+1 << " " << gs->N() << endl;

    Light_Stack<Cluster_Node *> S (TD->Nb_Clusters());
    Cluster_Node * cl;

    int num_cluster_init = 0;
    for (int num_ct = 0; num_ct < TD->Get_Cluster_Tree_Number(); num_ct++)
    {
      for (map<int,Cluster_Node *>::iterator iter = TD->Get_Cluster_Tree (num_ct)->Begin_List (); iter != TD->Get_Cluster_Tree (num_ct)->End_List (); iter++)
      {
        cout << "b " << num_cluster_init + (*iter).first + 1;
        for (Light_Vector<vertex>::iterator iter_v = (*iter).second->begin(); iter_v != (*iter).second->end(); iter_v++)
          cout << " " << *iter_v+1;
        cout << endl;
      }
      num_cluster_init += TD->Get_Cluster_Tree (num_ct)->Get_Max_Label() + 1;
    }
    
    
    num_cluster_init = 0;    
    for (int num_ct = 0; num_ct < TD->Get_Cluster_Tree_Number(); num_ct++)
    {
      S.push (TD->Get_Cluster_Tree (num_ct)->Get_Root());
      
      do
      {
        cl = S.top();
        S.pop();

        int num = cl->Get_Parent_Num();
        if (num != -1)
          cout << num_cluster_init + num + 1  << " " << num_cluster_init + cl->Get_Num()+1 << endl;

        
        for (deque<Child_Node *>::iterator iter = TD->Get_Cluster_Tree (num_ct)->Begin_Neighbor (cl->Get_Num()); iter != TD->Get_Cluster_Tree (num_ct)->End_Neighbor (cl->Get_Num()); iter++)
          if ((*iter)->Get_Cluster_Num() != num)
            S.push((*iter)->Get_Cluster());
      }
      while (! S.is_empty());
      
      num_cluster_init += TD->Get_Cluster_Tree (num_ct)->Get_Max_Label() + 1;
    }

    num_cluster_init = 0;    
    for (int num_ct = 0; num_ct < TD->Get_Cluster_Tree_Number()-1; num_ct++)
    {
      int root = num_cluster_init + TD->Get_Cluster_Tree (num_ct)->Get_Root_Num();
      num_cluster_init += TD->Get_Cluster_Tree (num_ct)->Get_Max_Label() + 1;
      cout << root+1 << " " << num_cluster_init + (TD->Get_Cluster_Tree (num_ct+1)->Get_Root_Num())+1 << endl;
    }
		
		delete TD;
		delete gs;
	}
	
  catch (string error)
 	{
		cerr << error << endl;
		delete TD;
		delete gs;

		return 1;
	}

 	catch (char const * error)
 	{
		delete TD;
		delete gs;

		cerr << error << endl;
		return 1;
	}

  return 0;
}
