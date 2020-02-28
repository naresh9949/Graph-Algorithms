/*
	KrusKals-Algorithm using disjoint sets...
	Time Complexity = O(ElogE) or O(ElogV)
	Space Complexity = O(E+V)
*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// Structure of a set element 
struct node
{
	int data;
	int rank;
	struct node* parent;
};


// Structure of a edge
struct Edge
{
	int s,d,w;
};


// To create a Set
node* Make_Set(int data,map<int,node*> &m)
{
	node* n = new node();
	n->data = data;
	n->rank = 0;
	n->parent = n;

	m[data] = n;

	return n;
	cout<<"MAked"<<endl;
}


// Find the parent element of set
int Find(node *n)
{
	//node p = n->parent;

	if(n->parent==n)
		return n->data;
	else
		return Find(n->parent);

	return -1;
}


// To find Union of Two sets
void Union(node* n1,node* n2,std::map<int, node*> &m)
{
	int p1 = Find(n1);
	int p2 = Find(n2);

	if(p1==p2)
		return ;
	if(m[p1]->rank>=m[p2]->rank)
	{
		m[p1]->rank = (m[p1]->rank==m[p2]->rank)?m[p1]->rank+1:m[p1]->rank;
		//m[p1]->rank = m[p1]->rank+m[p2]->rank;
		m[p2]->parent = m[p1];
	}
	else
	{
		m[p1]->parent = m[p2];
		//m[p2]->rank = m[p1]->rank+m[p2]->rank;	
	}

}


bool compare(Edge e1,Edge e2)
{
	return e1.w<e2.w;
}


// Prims Algorithm......Hear
// E[] ->edge array
// n->no.of edges
//v-> no.of vertices

void Prims_Algorithm(Edge E[],int n,int v)
{
	std::map<int, node*> m;
	for(int i=1;i<=v;i++)
		Make_Set(i,m);
	sort(E,E+n,compare);
	//for(int i=0;i<n;i++)
	//	cout<<E[i].s<<":"<<E[i].d<<"="<<E[i].w<<endl;

	int edge_count = 0;
	int i = 0;

	Edge Result[v-1];

	while(i<n && edge_count<=v-1)
	{
		Edge e = E[i];

		int p1 = Find(m[e.s]);
		int p2 = Find(m[e.d]);

		if(p1!=p2)
		{
			Result[edge_count] = E[i];
			edge_count++;
		}
		i++;
	}

	for(int i=0;i<v-1;i++)
		cout<<Result[i].s<<":"<<Result[i].d<<"="<<Result[i].w<<endl;


}

int main()
{
	int n=6;
	int e=7;
	
	Edge E[e];

	E[0].s = 1;
	E[0].d = 2;
	E[0].w = 1;

	E[1].s = 1;
	E[1].d = 3;
	E[1].w = 1;

	E[2].s = 2;
	E[2].d = 5;
	E[2].w = 8;

	E[3].s = 2;
	E[3].d = 6;
	E[3].w = 4;

	E[4].s = 3;
	E[4].d = 5;
	E[4].w = 2;

	E[5].s = 4;
	E[5].d = 5;
	E[5].w = 4;

	E[6].s = 4;
	E[6].d = 6;
	E[6].w = 3;

	Prims_Algorithm(E,e,n);

}

