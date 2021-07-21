#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* This funtcion is here just to test  */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int find_1(string s,int st,int end)
{
	if(st>end)return -1;
	
	stack <char> stt;
	
	for(int i=st;i<=end;i++)
	{
		if(s[i]=='(')
		{
			stt.push(s[i]);
		}
		else if(s[i]==')')
		{
			if(stt.top()=='(')
			{
				stt.pop();
				
				if(stt.empty())return i;
			}
		}
	}
	return -1;
}
Node* find(string s,int st,int end)
{
	if(st>end)return NULL;
	
	Node* root = newNode(s[st]-'0');
	int index = -1;
	
	if(st+1<=end&&s[st+1]=='(')
	{
		index = find_1(s,st+1,end);
	}
	if(index!=-1)
	{
		root->left = find(s,st+2,index-1);
		root->right = find(s,index+2,end-1);
	}
	return root;
}
int main()
{
	string s;
	cin >>s;
	Node* root = find(s,0,s.length()-1);
	preOrder(root);
}
