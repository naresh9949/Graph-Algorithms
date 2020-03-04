
/*
 
 Floyed Warshall Algorithm to find All pairs Shortest Path...

 code is Developed by NARESH KOLLIPORA..

*/


#include<iostream>
#include<stack>
#include<vector>
#define F -12345
#define INT_MAX1 123456
using namespace std;

struct node
{
	int d,w;
};

class Graph 
{ 
	int v; 
	vector<node> *e; 

public: 
	Graph(int V); 
	void addEdge(int u, int v,int wt); 
	void Show();
	int IsPathExist(int u,int v);
	void Floyed_Warshall();
}; 


Graph :: Graph(int x)
{
	v = x;
	e = new vector<node>[x];
}

void Graph :: addEdge(int u,int vt,int wt)
{
	node n1;
	n1.d = vt;
	n1.w = wt;
	e[u].push_back(n1);
	//e[v].push_back(u);
}

void Graph :: Show()
{
	for(int i=0;i<v;i++)
	{
		cout<<i<<" :";
		std::vector<node> :: iterator it;
		for(it=e[i].begin();it!=e[i].end();it++)
		{
			node n1 = *it;
			cout<<n1.d<<"("<<n1.w<<")"<<"  ";
		}
		cout<<endl;
	}
}

int Graph:: IsPathExist(int u,int v)
{
	std::vector<node> :: iterator it;
	for(it=e[u].begin();it!=e[u].end();it++)
	{
		node n1 = *it;
		if(n1.d==v)
			return n1.w;	
	}
	return F;
}

void Graph :: Floyed_Warshall()
{
	int PathMatrix[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j)
				PathMatrix[i][j] = 0;
			else{
				int wt = IsPathExist(i,j);
				if(wt!=F)
					PathMatrix[i][j] = wt;
				else
					PathMatrix[i][j] = INT_MAX1;
			}

		}
	}

	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				//if(i!=j){
				if(PathMatrix[i][j] > (PathMatrix[i][k]+PathMatrix[k][j]))
					PathMatrix[i][j] = PathMatrix[i][k]+PathMatrix[k][j] ;
				//}
				
			}
		}
	}


	cout<<"\t";

	for(int i=0;i<v;i++)
		cout<<i<<"\t";
	cout<<endl;

	cout<<"\t";

	for(int i=0;i<v;i++)
		cout<<"----";
	cout<<endl;

	for(int i=0;i<v;i++)
	{
		cout<<i<<"";
		cout<<"|\t";
		for(int j=0;j<v;j++)
		{
			if(PathMatrix[i][j]==INT_MAX)
				cout<<"I"<<"\t";
			else
			cout<<PathMatrix[i][j]<<"\t";	
		}
		cout<<endl;

	}
}



int main()
{
	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,0,8);
	g.addEdge(1,2,2);
	g.addEdge(2,0,5);
	g.addEdge(2,3,1);
	g.addEdge(3,0,2);
	g.addEdge(0,3,7);


	g.Floyed_Warshall();

}
