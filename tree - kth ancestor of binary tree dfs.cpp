#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// temporary node to keep track of Node returned 
// from previous recursive call during backtrack 
Node* temp = NULL; 

Node* kthAncestorDFS(Node* root,int node,int k)
{
	if(root==NULL)return NULL;
	
	if(root->data==node||(temp=kthAncestorDFS(root->left,node,k))||(temp=kthAncestorDFS(root->right,node,k)))
	{
		if(k>0)k--;
		else if(k==0)
		{
			cout<<"Kth Ancestor : "<<root->data;
			
			return NULL;
		}
		return root;
	}
}
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
int main() 
{ 
    // Let us create binary tree shown in above diagram 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    int k = 2; 
    int node = 5; 
  
    // print kth ancestor of given node 
    Node* parent = kthAncestorDFS(root,node,k); 
      
    // check if parent is not NULL, it means 
    // there is no Kth ancestor of the node 
    if (parent) 
        cout << "-1"; 
      
    return 0; 
} 
