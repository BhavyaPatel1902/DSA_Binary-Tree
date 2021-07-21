#include <bits/stdc++.h> 
using namespace std; 
void printVector(const vector<int>& v, int i) 
{ 
    for (int j=i; j<v.size(); j++) 
        cout << v[j] << " "; 
    cout << endl; 
} 
struct Node 
{ 
    int data; 
    Node *left,*right; 
    Node(int x) 
    { 
        data = x; 
        left = right = NULL; 
    } 
};
void printpathutil(Node* root,vector <int> &path,int k)
{
	if(root==NULL)return;
	
	path.push_back(root->data);
	
	printpathutil(root->left,path,k);
	
	printpathutil(root->right,path,k);
	
	
	int f = 0;
	for(int j=path.size();j>=0;j--)
	{
		f = f + path[j];
		
		if(f==k)printVector(path,j);
	}
	path.pop_back();
}
void printKPath(Node* root,int k)
{
	vector <int> path;
	printpathutil(root,path,k);
}
int main() 
{ 
    Node *root = new Node(1); 
    root->left = new Node(3); 
    root->left->left = new Node(2); 
    root->left->right = new Node(1); 
    root->left->right->left = new Node(1); 
    root->right = new Node(-1); 
    root->right->left = new Node(4); 
    root->right->left->left = new Node(1); 
    root->right->left->right = new Node(2); 
    root->right->right = new Node(5); 
    root->right->right->right = new Node(2); 
  
    int k = 5; 
    printKPath(root, k); 
  
    return 0; 
}
