#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void generateall(Node* root,int ancestor[])
{
	ancestor[root->data] = -1;
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		if(temp->left)
		{
			ancestor[temp->left->data] = temp->data;
			q.push(temp->left);
		}
		if(temp->right)
		{
			ancestor[temp->right->data] = temp->data;
			q.push(temp->right);
		}
	}
}
int kthAncestor(Node* root,int n,int k,int node)
{
	int ancestor[n+1] = {0};
	
	generateall(root,ancestor);
	
	int ct = 0;
	
	while(node!=-1)
	{
		node = ancestor[node];
		ct++;
		if(k==ct)break;
	}
	return node;
}
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Driver program to test above functions
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
    cout<<kthAncestor(root,5,k,node);
    return 0;
}*/
