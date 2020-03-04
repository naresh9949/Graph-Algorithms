#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Graph 
{ 
	int v; 
	vector<int> *e; 

public: 
	Graph(int V); 
	void addEdge(int u, int v); 
	void Show();
	void DFSUtill(int v,bool visited[],stack<int> &s);
	void DFS(int v,stack<int> &s);
	void Topological_Sort();
}; 


Graph :: Graph(int x)
{
	v = x;
	e = new vector<int>[x];
}

void Graph :: addEdge(int u,int vt)
{
	e[u].push_back(vt);
	//e[v].push_back(u);
}

void Graph :: Show()
{
	for(int i=0;i<v;i++)
	{
		cout<<i<<" :";
		std::vector<int> :: iterator it;
		for(it=e[i].begin();it!=e[i].end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

void Graph :: DFS(int vertex,stack<int> &s)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=0;
	DFSUtill(vertex,visited,s);
	
}


void Graph :: DFSUtill(int ver,bool visited[],stack<int> &s)
{
	visited[ver] = 1;
	std::vector<int> :: iterator it;
	for(it=e[ver].begin();it!=e[ver].end();it++)
	{
		if(visited[*it]==0)
			DFSUtill(*it,visited,s);
	}
	s.push(ver);

}

void Graph :: Topological_Sort()
{
	stack<int> s;
	this->DFS(0,s);
	while(!s.empty())
	{
		int t = s.top();
		s.pop();
		cout<<t<<" ";
	}
	cout<<endl;
}

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,4);

	g.Topological_Sort();

}
