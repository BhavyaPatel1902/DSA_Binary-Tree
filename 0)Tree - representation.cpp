#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	 int data;
	 Node* right;
	 Node* left;
};
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	
	return temp;
}
Node* insert(Node* root,int data)
{
	if(root==NULL)
	{
		root = newNode(data);
		return root;
	}
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = newNode(data);
			return root;
		}
		
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = newNode(data);
			return root;
		}
	}
}
void deletedeep(Node* root,Node* deep)
{
	queue <Node*> q;
	q.push(root);
	
	Node* temp;
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp==deep)
		{
			temp = NULL;
			delete(deep);
			return;
		}
		
		if(temp->right)
		{
			if(temp->right==deep)
			{
				temp->right = NULL;
				delete(temp->right);
				return;
			}
			else
			{
				q.push(temp->right);
			}
		}
		
		if(temp->left)
		{
			if(temp->left==deep)
			{
				temp->left = NULL;
				delete(temp->left);
				return;
			}
			else
			{
				q.push(temp->left);
			}
		}
	}
}
Node* deletion(Node* root,int data)
{
	if(root==NULL)return NULL;
	
	if(root->left==NULL&&root->right==NULL)
	{
		if(root->data==data)
		{
			return NULL;
		}
		else
		{
			return root;
		}
	}
	
	queue <Node*> q;
	q.push(root);
	
	Node* temp1 = NULL;
	
	Node* temp;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->data==data)
		{
			temp1 = temp;
		}
		if(temp->left)q.push(temp->left);
		
		if(temp->right)q.push(temp->right);
	}
	if(temp1!=NULL)
	{
		int key = temp->data;
			
		deletedeep(root,temp);
			
		temp1->data = key;
	}
	return root;
}
vector <int> levelOrder(Node* node)
{
    vector <int> ans;
    
    if(node==NULL)return ans;
    
    queue <Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        Node* temp = q.front();
        ans.push_back(temp->data);
        q.pop();
        
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
    return ans;
}
vector <int> reverseLevelOrder(Node *root)
{
    vector <int> ans;
    
    if(root==NULL)return ans;
    
    queue <Node*> q;
    stack <Node*> st;
    
    q.push(root);
    
    while(!q.empty())
    {
        Node* temp = q.front();
        st.push(temp);
        q.pop();
        
        if(temp->right)q.push(temp->right);
        
        if(temp->left)q.push(temp->left);
    }
    
    while(!st.empty())
    {
        Node* temp = st.top();
        ans.push_back(temp->data);
        st.pop();
    }
    return ans;
}
int height(struct Node* node)
{
    if(node==NULL)return 0;
        
    return max(height(node->left),height(node->right))+1;
}
int diameter(Node* root) 
{
    if(root==NULL)return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    
    return max((lh+rh+1),max(ld,rd));
}
void mirror(Node* node) 
{
     if(node==NULL)return;
     
     mirror(node->left);
     mirror(node->right);
     swap(node->left,node->right);
}
void inorder(Node* temp)
{
	if(temp==NULL)return;
	
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
void preorder(Node* temp)
{
	if(temp==NULL)return;
	
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}
void postorder(Node* temp)
{
	if(temp==NULL)return;
	
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}
void inorder_iterative(Node* root)
{
	
}
void preorder_iterative(Node* root)
{
	
}
void postorder_iterative(Node* root)
{
	
}
int main()
{
	Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    
	inorder(root);
	cout<<endl;
	
	insert(root,12);
	
	inorder(root);
	
	root = deletion(root,12);
	
	cout<<endl;
	inorder(root);
}
