#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
int findlvl(Node* root,int k,int lvl)
{
	if(root==NULL)return -1;
	
	if(root->key==k)return lvl;
	
	int left = findlvl(root->left,k,lvl+1);
	
	if(left==-1)return findlvl(root->right,k,lvl+1);
	
	return left;
}
Node* find(Node* root,int a,int b)
{
	if(root==NULL)return root;
	
	if(root->key==a||root->key==b)return root;
	
	Node* l = find(root->left,a,b);
	Node* r = find(root->right,a,b);
	
	if(l&&r)return root;
	if(l==NULL&&r==NULL)return NULL;
	
	if(l!=NULL)return l;
	
	return r;
}
int findDistance(Node* root,int a,int b)
{
	Node* lca = find(root,a,b);
	
	int d1 = findlvl(lca,a,0);
	int d2 = findlvl(lca,b,0);
	
	return d1+d2;
}
int main()
{
    // Let us create binary tree given in
    // the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
