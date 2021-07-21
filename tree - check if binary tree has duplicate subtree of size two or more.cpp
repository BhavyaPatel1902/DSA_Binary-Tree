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
string inorder(Node* root,unordered_map <string,int> &mp,int &flag)
{
	if(root==NULL)return "";
	
	string s = "(";
	s = s + inorder(root->left,mp,flag);
	s = s + to_string(root->data);
	s = s + inorder(root->right,mp,flag);
	s = s + ")";
    
    
    if(mp[s]>=1&&s.length()>=5)
    {
    	flag = 1;
	}
	mp[s]++;
	
	return s;
}
void printAllDups(Node* root)
{
	unordered_map <string,int> mp;
	int flag = 0;
	inorder(root,mp,flag);
	if(flag==1)cout<<1<<endl;
	else cout<<0<<endl;
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
