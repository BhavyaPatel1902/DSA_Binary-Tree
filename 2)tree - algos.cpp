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
void inorder(Node* temp)
{
	if(temp==NULL)return;
	
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
//make sumtree
void sumtree(Node* node)
{
	if(node==NULL)retturn;
	
	if(node->left==NULL&&node->right==NULL)node->data=0;
	else
	{
		int left = 0;
		int right = 0;
		
		if(root->left)
		{
			left = node->left->data;
			sumtree(node->left);
			left = left + node->left->data;
		}
		
		if(root->right)
		{
			right = node->right->data;
			sumtree(node->right);
			right = right + node->right->data;
		}
		
		node->data = left+right;
	}
}
//check for sumtree
bool isLeaf(Node* root)
{
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    return 0;
}
bool isSumTree(Node* root)
{
     if(root==NULL||isLeaf(root))return true;
     
     int ls = 0;
     int rs = 0;
     
     if(isSumTree(root->left)&&isSumTree(root->right))
     {
         if(root->left==NULL)ls = 0;
         else if(isLeaf(root->left))ls = root->left->data;
         else ls = 2*(root->left->data);
         
         if(root->right==NULL)rs = 0;
         else if(isLeaf(root->right))rs = root->right->data;
         else rs = 2*(root->right->data);
         
         return (root->data==(ls+rs));
     }
     return 0;
}

int sum_1(Node* root)
{
	if(root==NULL)return 0;
	
	return sum(root->left)+root->data+sum(root->right);
}
bool isSum_2(Node* root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))return 1;
	
	int ls = sum(root->left);
	int rs = sum(root->right);
	
	if((root->data==(ls+rs))&&isSum_2(root->left)&&isSum_2(root->right))return 1;
	
	return 0;
}
//check for all leafs at same level
bool check_1(Node* root,int level,int &first)
{
    if(root==NULL)return 1;
    
    if(root->left==NULL&&root->right==NULL)
    {
        if(first==0)
        {
            first = level;
            return true;
        }
        
        return (level==first);
    }
    
    return check_1(root->left,level+1,first)&&check_1(root->right,level+1,first);
}
bool check(Node *root)
{
    int level = 0;
    int leaflevel = 0;
    
    return check_1(root,level,leaflevel);
}
int checkLevelLeafNode(Node* root)
{
    if (!root)
        return 1;

    queue<Node*> q;
    q.push(root);
  
     int result = INT_MAX;
     int level = 0;
 
    while (!q.empty()) 
	{
        int size = q.size();
        level += 1;
 
        while(size > 0)
		{
            Node* temp = q.front();
            q.pop();
            if (temp->left)
			{
                q.push(temp->left);
                if(!temp->left->right && !temp->left->left)
				{
 
                    if (result == INT_MAX)
                        result = level;
                    else if (result != level)
                        return 0;                    
                }
            }
            if (temp->right)
			{
                q.push(temp->right);

                if (!temp->right->left && !temp->right->right)
                {
                    if (result == INT_MAX)
                        result = level;
                     
                    else if(result != level)
                        return 0;
                     
               }
           }
               size -= 1;
        }    
    }
    return 1;
}
//check two tree are mirror or not
bool aremirror(Node* a,Node* b)
{
	if(a==NULL&&b==NULL)return 1;
	
	if(a==NULL||b==NULL)return 0;
	
	return (a->data==b->data)&&aremirror(a->left,b->right)&&aremirror(a->right,b->left);
}

//sum of nodes on the longest path from root to leaf node
void sum_1(Node* root,int sum,int len,int &maxsum,int &maxlen)
{
    if(root==NULL)
    {
        if(maxlen<len)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if(maxlen==len&&maxsum<sum)
        {
            maxsum = sum;
        }
        return;
    }
    
    sum_1(root->left,sum+root->data,len+1,maxsum,maxlen);
    sum_1(root->right,sum+root->data,len+1,maxsum,maxlen);
}
int sumOfLongRootToLeafPath(Node* root)
{
    if(root==NULL)return 0;
    
    int maxsum = INT_MIN;
    int maxlen = 0;
     
    sum_1(root,0,0,maxsum,maxlen);
    
    return maxsum;
}
//check is binary tree is balanced or not
int height(Node* root)
{
    if(root==NULL)return 0;
    
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node *root)
{
    if(root==NULL)return true;
    
    int lh,rh;
    
    lh = height(root->left);
    
    rh = height(root->right);
    
    return (abs(lh-rh)<=1)&&isBalanced(root->left)&&isBalanced(root->right);
    
}
//find largest subtree sum in the binary tree
void find_1(Node* root,int &ans)
{
	if(root==NULL)return;
	
	int sum = root->data+find_1(root->left,ans)+find_1(root->right,ans);
	
	ans = max(ans,sum);
}
int find(Node* root)
{
	int ans = INT_MIN;
	if(root==NULL)return ans;
	
	find_1(root,ans);
	
	return ans;
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
	
	
}
