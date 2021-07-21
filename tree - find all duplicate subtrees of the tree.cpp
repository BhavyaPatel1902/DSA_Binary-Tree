#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
string inorder(Node* root,map <string,int> &mp)
{
	if(root==NULL)return "";
	
	string s = "(";
	s = s + inorder(root->left,mp);
	s = s + to_string(root->data);
	s = s + inorder(root->right,mp);
	s = s + ")";
    
    
    if(mp[s]>=1)
    {
    	cout<<root->data<<" ";
	}
	mp[s]++;
	
	
	return s;
}
void printAllDups(Node* root)
{
	unordered_map <string,int> mp;
	inorder(root,mp);
}
int main()
{
	Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}
