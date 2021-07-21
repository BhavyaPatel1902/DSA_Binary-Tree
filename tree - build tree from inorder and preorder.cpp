#include<bits/stdc++.h>
using namespace std;
class node 
{ 
    public:
    char data; 
    node* left; 
    node* right; 
};
node* newNode(char data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
 
    return (Node); 
} 
 
/* This funtcion is here just to test buildTree() */
void printInorder(node* node) 
{ 
    if (node == NULL) 
        return; 
 
    /* first recur on left child */
    printInorder(node->left); 
 
    /* then print the data of node */
    cout<<node->data<<" "; 
 
    /* now recur on right child */
    printInorder(node->right); 
} 

int search(char in[],int st,int end,int key)
{
	int i;
	for(i=st;i<=end;i++)
	{
		if(in[i]==key)return i;
	}
}
node* buildTree(char in[],char pre[],int st,int end)
{
	if(st>end)return NULL;
	
	static int preidx = 0;
	
	node* root = newNode(pre[preidx++]);
	
	if(st==end)return root;
	
	int inidx = search(in,st,end,root->data);
	
	root->left = buildTree(in,pre,st,inidx-1);
	
	root->right = buildTree(in,pre,inidx+1,end);
	
	return root;
}
int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    node* root = buildTree(in, pre, 0, len - 1); 
 
    /* Let us test the built tree by 
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n"; 
    printInorder(root); 
}
