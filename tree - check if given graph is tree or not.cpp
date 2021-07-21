#include<bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj; // Pointer to an array for adjacency lists 
    bool iscycle(int v, bool visited[], int parent); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isTree();   // returns true if graph is tree 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Add v to w’s list. 
} 
bool Graph :: iscycle(int v,bool visited[],int parent)
{
	visited[v] = true;
	
	for(auto u : adj[v])
	{
		if(!visited[u])
		{
			if(iscycle(u,visited,v))return true;
		}
		else if(u!=parent)
		{
			return true;
		}
	}
	return false;
}
bool Graph::isTree()
{
	bool visited[V];
	for(int i=0;i<V;i++)visited[i] = false;
	
	if(iscycle(0,visited,-1))return false;
	
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)return false;
	}
	return true;
}
int main()
{
	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n"; 
  
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n"; 
  
    return 0; 
}
