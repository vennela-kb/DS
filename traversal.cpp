#include<iostream>
using namespace std;
#include<stdlib.h>

struct node
{
 char info;
 struct node *left,*right;
};
typedef struct node NODE;

NODE *maketree(char x)
{
 NODE *p;
 p=(NODE*)malloc(sizeof(NODE));
 p->info=x;
 p->left=NULL;
 p->right=NULL;
 return p;
}

void preorder(NODE *tree)
{
 if(tree!=NULL)
 {
  cout<<tree->info<<endl;
  preorder(tree->left);
  preorder(tree->right);
 }
}

void inorder(NODE *tree)
{
 if(tree!=NULL)
 {
  inorder(tree->left);
  cout<<tree->info<<endl;
  inorder(tree->right);
 }
}

void postorder(NODE *tree)
{
 if(tree!=NULL)
 {
  postorder(tree->left);
  postorder(tree->right);
  cout<<tree->info<<endl;
 }
}

int main()
{
 NODE *tree; 
 tree=maketree('A');
 tree->left=maketree('B');
 tree->right=maketree('C');
 cout<<"\nPreorder Traversal"<<endl;
 preorder(tree);
 cout<<"\nInorder Traversal"<<endl;
 inorder(tree);
 cout<<"\nPostorder Traversal"<<endl; 
 postorder(tree);
}
