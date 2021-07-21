void left_1(Node* root,int lvl,int &maxi,vector <int> &ans)
{
    if(root==NULL)return;
    
    if(maxi<lvl)
    {
        ans.push_back(root->data);
        maxi = lvl;
    }
    
    left_1(root->left,lvl+1,maxi,ans);
    left_1(root->right,lvl+1,maxi,ans);
}
vector<int> leftView(Node *root)
{
    int maxi = 0;
    vector <int> ans;
    
    left_1(root,1,maxi,ans);
    
    return ans;
}
void leftview(Node* root)
{
	if(root==NULL)return;
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
        int n = q.size();
        
        for(int i=1;i<=n;i++)
        {
        	Node* temp = q.front();
        	q.pop();
        	
        	if(i==1)cout<<temp->data<<" ";
        	
        	if(temp->left)q.push(temp->left);
        	
        	if(temp->right)q.push(temp->right);
		}
	}
}
void right_1(Node* root,int lvl,int &maxi,vector <int> &ans)
{
    if(root==NULL)return;
    
    if(maxi<lvl)
    {
        ans.push_back(root->data);
        maxi = lvl;
    }
    
    right_1(root->right,lvl+1,maxi,ans);
    right_1(root->left,lvl+1,maxi,ans);
}
vector<int> RightView(Node *root)
{
    int maxi = 0;
    vector <int> ans;
    
    right_1(root,1,maxi,ans);
    
    return ans;
}
void rightview(Node* root)
{
	if(root==NULL)return;
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		int n = q.size();
		
		for(int i=1;i<=n;i++)
		{
			Node* temp = q.front();
			q.pop();
			
			if(i==n)cout<<temp->data<<" ";
			
			if(temp->left)q.push(temp->left);
			
			if(temp->right)q.push(temp->right);
		}
	}
}
//boundry traversal of the binary tree
void printleft(Node* root,vector <int> &ans)
{
	if(root==NULL)return;
	
	if(root->left)
	{
		ans.push_back(root->data);
		printleft(root->left,ans);
	}
	else if(root->right)
	{
		ans.push_back(root->data);
		printleft(root->right,ans);
	}
}
void printright(Node* root,vector <int> &ans)
{
	if(root==NULL)return;
	
	if(root->right)
	{
		printright(root->right,ans);
		ans.push_back(root->data);
	}
	else if(root->left)
	{
		printright(root->left,ans);
		ans.push_back(root->data);
	}
}
void printleaf(Node* root,vector <int> &ans)
{
	if(root==NULL)return;
	
	printleaf(root->left,ans);
	
	if(root->left==NULL&&root->right==NULL)
	{
		ans.push_back(root->data);
	}
	
	printleaf(root->right,ans);
}
vector <int> boundry(Node* root)
{
	vector <int> ans;
	
	if(root==NULL)return ans;
	
	ans.push_back(root->data);
	
	printleft(root->left);
	
	printleaf(root->left);
	printleaf(root->right);
	
	printright(root->right);
	
}
void diagonalprint(Node* root,int d,map <int,vector<int>> &mp)
{
	if(root==NULL)return;
	
	mp[d].push_back(root->data);
	
	diagonalprint(root->left,d+1,mp);
	
	diagonalprint(root->right,d,mp);
}
void diagonal(Node* root)
{
	map <int,vector <int> > mp;
	diagonalprint(root,0,mp);
	
	for(auto it : mp)
	{
		vector <int> v = it->second;
		
		for(auto i : v)
		{
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
vector <int> zigzag(Node* root)
{
	vector <int> ans;
	if(root==NULL)return ans;
	
	stack <Node*> current;
	stack <Node*> next1;
	
	bool lefttoright = true;
	
	current.push(root);
	
	while(!current.empty())
	{
		Node* temp = current.top();
		current.pop();
		
		if(temp)
		{
			ans.push_back(temp->data);
			if(lefttoright)
			{
				next1.push(temp->left);
				next1.push(temp->right);
			}
			else
			{
				next1.push(temp->right);
				next1.push(temp->left);
			}
		}
		
		if(current.empty())
		{
			lefttoright = !lefttoright;
			
			swap(current,next1);
		}
	}
	return ans;
}
