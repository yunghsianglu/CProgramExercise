#ifndef TREE_H
#define TREE_H
typedef struct tnode
{
  int size;
  char * state;
  int nummove;
  char * moves; // from the root
  struct tnode * left;
  struct tnode * right;
} TreeNode;

TreeNode * Tree_insert(TreeNode * root, int sz,
		       const char * st, int num,
		       const char * mvs);
TreeNode * Tree_search(TreeNode * root, const char * state);
void Tree_print(TreeNode * root);
void Tree_destroy(TreeNode * root);
// report the number of nodes in a tree
int Tree_size(TreeNode * root);
int Tree_height(TreeNode * root);
void Tree_fillState(TreeNode * root, char ** reachableState,
		    int * ind);
#endif
