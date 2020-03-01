/*
	Bellman-Ford Algorithm with directed Graph.
	Time Complexity = O(VE).
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Edge
{
	int s;//Starting Point
	int d;//destination
	int w;//Weight
};

class Graph 
{ 
	int V; 
	vector<Edge> E; 

public: 
	Graph(int V); 
	void addEdge(int u, int v, int w); 
	void Bellman_Ford(int s);
	bool IS_NegativeCycle_Exist(); // returns TRUE if negative cycle exist
}; 
 
Graph::Graph(int V) 
{ 
	this->V = V;  
} 

void Graph::addEdge(int u, int v, int w1) 
{ 

	Edge e;
	e.s = u;
	e.d = v;
	e.w = w1;
	E.push_back(e);

	e.s = v;
	e.d = u;

//	E.push_back(e);

} 

void Graph :: Bellman_Ford(int src)
{
	map<int ,pair<int,int> > mp;

	for(int i=0;i<V;i++)
	{
		pair<int ,int> p;
		p.first = -1;
		p.second = INT_MAX;

		if(i==src)
			p.second = 0;

		mp[i] = p;
	}

	for(int i=0;i<V-1;i++)
	{
		vector<Edge> :: iterator it;

		for(it=E.begin();it!=E.end();it++)
		{
			Edge e = *it;
			if(mp[e.d].second > mp[e.s].second+e.w)
			{
				mp[e.d].second = mp[e.s].second+e.w;

				mp[e.d].first = e.s;
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		pair<int ,int> p;
		
		p = mp[i];

		cout<<i<<"    "<<p.first<<"    "<<p.second<<endl;
	}
}


bool Graph:: IS_NegativeCycle_Exist()
{
	map<int ,pair<int,int> > mp;

	for(int i=0;i<V;i++)
	{
		pair<int ,int> p;
		p.first = -1;
		p.second = INT_MAX;

		if(i==0)
			p.second = 0;

		mp[i] = p;
	}

	for(int i=0;i<V-1;i++)
	{
		vector<Edge> :: iterator it;

		for(it=E.begin();it!=E.end();it++)
		{
			Edge e = *it;
			if(mp[e.d].second > mp[e.s].second+e.w)
			{
				mp[e.d].second = mp[e.s].second+e.w;

				mp[e.d].first = e.s;
			}
		}
	}


	for(int i=0;i<V-1;i++)
	{
		vector<Edge> :: iterator it;

		for(it=E.begin();it!=E.end();it++)
		{
			Edge e = *it;
			if(mp[e.d].second > mp[e.s].second+e.w)
			{
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	Graph g(5);

	g.addEdge(0, 1, -1); 
	g.addEdge(0, 2, 4); 
	g.addEdge(1, 2, 3) ;
	g.addEdge(1, 3, 2) ;
	g.addEdge(1, 4, 2) ;
	g.addEdge(3, 2, 5) ;
	g.addEdge(3, 1, 1) ;
	g.addEdge(4, 3, -3) ;

	int src = 0;

	g.Bellman_Ford(src);

	if(g.IS_NegativeCycle_Exist())
		cout<<"YES"<<endl;
}