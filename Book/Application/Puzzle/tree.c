#include "tree.h"
#include "utility.h"
#include <stdlib.h>
#include <stdio.h>
static TreeNode * TreeNode_construct(int sz,
				     const char * st,
				     int num,
				     const char * mvs)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> size = sz;
  int length = sz * sz;
  tn -> state = malloc(sizeof(char) * length);
  int ind;
  for (ind = 0; ind < length; ind ++)
    {
      tn -> state[ind] = st[ind];
    }
  tn -> nummove = num;
  if (num > 0)
    {
      tn -> moves = malloc(sizeof(char) * num);
      for (ind = 0; ind < num; ind ++)
	{
	  tn -> moves[ind] = mvs[ind];
	}
    }
  else
    {
      tn -> moves = NULL;
    }
  tn -> left = NULL;
  tn -> right = NULL;
  return tn;
}

// return 0 if the two states are the same
// return 1 if st1 is greater than st2 (lexicographically)
// return -1 if st1 is smaller than st2
static int compareState(int sz, const char * st1, const char * st2)
{
  int length = sz * sz;
  int ind;
  for (ind = 0; ind < length; ind ++)
    {
      if (st1[ind] > st2[ind])
	{
	  return 1;
	}
      if (st1[ind] < st2[ind])
	{
	  return -1;
	}
    }
  return 0;
}

TreeNode * Tree_insert(TreeNode * root, int sz, 
		       const char * st, int num,
		       const char * mvs)
{
  if (root == NULL)
    {
      return TreeNode_construct(sz, st, num, mvs);
    }
  // cannot use strcmp because the state may not end with '\0'
  int comp = compareState(sz, root -> state, st);
  if (comp == 0)
    {
      // this state is already in the tree, do nothing
      return root;
    }
  if (comp < 0)
    {
      root -> right = Tree_insert(root -> right, sz, st, num, mvs);
    }
  else
    {
      root -> left = Tree_insert(root -> left, sz, st, num, mvs);
    }
  return root;
}

TreeNode * Tree_search(TreeNode * root, const char * state)
{
  if (root == NULL)
    {
      return NULL;
    }
  int comp = compareState(root -> size, root -> state, state);
  if (comp == 0)
    {
      return root;
    }
  if (comp < 0)
    {
      return Tree_search(root -> right, state);
    }
  return Tree_search(root -> left, state);
}
				     
void Tree_destroy(TreeNode * root)
{
  if (root == NULL)
    {
      return;
    }
  Tree_destroy(root -> left);
  Tree_destroy(root -> right);
  
  // in  the reverse order of TreeNode_construct
  free (root -> moves);
  free (root -> state);
  free (root);
}

void Tree_print(TreeNode * root)
{
  if (root == NULL)
    {
      return;
    }
  int ind;
  if (root -> nummove > 0)
    {
      printf("moves: ");
      for (ind = 0; ind < root -> nummove; ind ++)
	{
	  printf("%c", root -> moves[ind]);
	}
      printf("\n");
    }
  int length = (root -> size) * (root -> size);
  printf("state: ");
  for (ind = 0; ind < length; ind ++)
    {
      printf("%c", root -> state[ind]);
    }
  printf("\n");
  char ** twoD = allocateTwoD(root -> size);
  oneD2twoD(root -> size, root -> state, twoD);
  printtwoD(root -> size, twoD);
  releaseTwoD(root -> size, twoD);
  Tree_print(root -> left);
  Tree_print(root -> right);
}

int Tree_size(TreeNode * root)
{
  if (root == NULL)
    {
      return 0;
    }
  return 1 + Tree_size(root -> left) + Tree_size(root -> right);
}

int Tree_height(TreeNode * root)
{
  if (root == NULL)
    {
      return 0;
    }
  int lh = Tree_height(root -> left);
  int rh = Tree_height(root -> right);
  if (lh > rh)
    {
      return 1 + lh;
    }
  return 1 + rh;
}

void Tree_fillState(TreeNode * root, 
		    char ** reachableState,
		    int * ind)
{
  if (root == NULL)
    {
      return;
    }
  reachableState[*ind] = copyState(root -> size, root -> state);
  (* ind) ++;
  Tree_fillState(root -> left, reachableState, ind);
  Tree_fillState(root -> right, reachableState, ind);
}
