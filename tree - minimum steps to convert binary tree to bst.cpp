#include<bits/stdc++.h>
using namespace std;
void inorder(int a[],vector <int> &v,int n,int idx)
{
	if(idx>=n)return;
	
	inorder(a,v,n,2*idx+1);
	v.push_back(a[idx]);
	inorder(a,v,n,2*idx+2);
}
int minswaps(vector <int> v)
{
	vector < pair <int,int> > ans(v.size());
	int res = 0;
	for(int i=0;i<v.size();i++)
	{
		ans[i].first = v[i];
		ans[i].second = i;
	}
	
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++)
	{
	   if(i==ans[i].second)continue;
	   else
	   {
	   	  swap(ans[i].first,ans[ans[i].second].first);
	   	  swap(ans[i].second,ans[ans[i].second].second);
	   }
	   
	   if(i!=ans[i].second)--i;
	   
	   res++;
	}
	return res;
}
int main()
{
	int n;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)cin >>a[i];
	vector <int> v;
	inorder(a,v,n,0);
	cout<<minswaps(v)<<endl;
}
