#include<iostream>
#include<vector>
using namespace std;
void AddEdge(int source,int destination,vector<int> v[])
{
	v[source].push_back(destination);
}

void DFS(vector<int> v[],int start,int visited[])
{
	visited[start]=1;
	cout<<start<<" ";
	vector<int> :: iterator it;
	for(it=v[start].begin();it!=v[start].end();it++)
		if(visited[*it]==0)
			DFS(v,*it,visited);
}

void DFS_Traversal(int start,std::vector<int> v[],int n)
{
	int visited[n+1];
	for(int i=0;i<n+1;i++)
		visited[i]=0;
	DFS(v,start,visited);
}
int main()
{
	std::vector<int> v[6];
	AddEdge(1,3,v);
	AddEdge(1,2,v);
	AddEdge(2,1,v);
	AddEdge(2,4,v);
	AddEdge(3,1,v);
	AddEdge(3,5,v);
	AddEdge(4,2,v);
	AddEdge(4,5,v);
	AddEdge(5,4,v);
	AddEdge(5,3,v);
	DFS_Traversal(1,v,5);
}