/*
	Kosaraju's Algorithm
	Time Complexity : O(E+V)

*/


#include<iostream>
#include<stack>
#include<list>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;

	void Fill_Order(int v,bool visited[],stack<int> &s);

	void DFSUtil(int v,bool visited[]);


public:
	Graph(int v);
	void Add_Edge(int s,int d);
	void Kosaraju_Algorithm();
	Graph Transpose();
};


Graph:: Graph(int v)
{
	this->v = v;
	this->adj = new list<int>[v];
}

void Graph::DFSUtil(int v,bool visited[])
{
	visited[v] = true;
	cout<<v<<" ";
	list<int> :: iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[*it]==0)
			DFSUtil(*it,visited);
	}
}



Graph Graph :: Transpose()
{
	Graph g(v);
	list<int> :: iterator it;
	for(int i=0;i<v;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			g.Add_Edge(*it,i);
			//erjfioejfoe
			//g.adj[*it].push_back(i);
		}
	}
	return g;
}



void Graph :: Add_Edge(int s,int e)
{
	adj[s].push_back(e);
}



void Graph :: Fill_Order(int v,bool visited[],stack<int> &s)
{
	visited[v] = true;
	//cout<<v<<" ";
	list<int> :: iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++)
		if(visited[*it]==0)
			Fill_Order(*it,visited,s);
	s.push(v);
}

void Graph :: Kosaraju_Algorithm()
{
	stack<int> s;

	bool *visited = new bool[v];

	for(int i=0;i<v;i++)
		visited[i]=0;

	for(int i=0;i<v;i++)
		if(visited[i]==0)
			Fill_Order(i,visited,s);

	Graph g = Transpose();

	for(int i=0;i<v;i++)
		visited[i]=0;

	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		if(visited[t]==0)
		{
			g.DFSUtil(t,visited);
			cout<<endl;
		}
	}

}

int main()
{
	Graph g(5);

	g.Add_Edge(1,0);
	g.Add_Edge(0,2);
	g.Add_Edge(2,1);
	g.Add_Edge(0,3);
	g.Add_Edge(3,4);
	g.Kosaraju_Algorithm();
}