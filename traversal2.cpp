#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	char data;
	struct node *left, *right;
};
typedef struct node NODE;
NODE* makeNode(char n)
{
	NODE *newn;
	newn = (NODE*)malloc(sizeof(NODE));
	newn -> data = n;
	newn -> left = NULL;
	newn -> right = NULL;
	return newn;
}
void preOrder(NODE *temp)
{
	if(temp != NULL)
        {
		cout << temp -> data << endl;
		preOrder(temp -> left);
		preOrder(temp -> right);
	}
} 
void inOrder(NODE *temp)
{
        if(temp != NULL)
        { 
                inOrder(temp -> left); 
                cout << temp -> data << endl; 
                inOrder(temp -> right); 
        } 
} 
void postOrder(NODE *temp)
{
        if(temp != NULL)
        { 
                postOrder(temp -> left); 
                postOrder(temp -> right); 
                cout << temp -> data << endl; 
        } 
} 
int main()
{
	NODE *tree;
	tree = makeNode('A');
	tree -> left = makeNode('B');
	tree -> right = makeNode('C');
	cout << "PreOrder: " << endl;
	preOrder(tree);
	cout << "InOrder: " << endl;
	inOrder(tree);
	cout << "PostOrder: " << endl;
	postOrder(tree);
}