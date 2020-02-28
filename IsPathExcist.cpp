#include<iostream>
#include<vector>
using namespace std;
void AddEdge(int source,int destination,vector<int> v[])
{
	v[source].push_back(destination);
}

bool DFS(vector<int> v[],int start,int visited[],int d)
{
	visited[start]=1;
	//cout<<start<<" ";
	vector<int> :: iterator it;
	for(it=v[start].begin();it!=v[start].end();it++){
		if(*it==d)
			return 1;
		else if(visited[*it]==0)
			return DFS(v,*it,visited,d);
	}
	return 0;
}

bool IsPathExcist(int start,int d,std::vector<int> v[],int n)
{
	int visited[n+1];
	for(int i=0;i<n+1;i++)
		visited[i]=0;
	return DFS(v,start,visited,d);
}
int main()
{
	std::vector<int> v[6];
	AddEdge(1,3,v);
	AddEdge(1,2,v);
	AddEdge(2,1,v);
	AddEdge(2,4,v);
	AddEdge(3,1,v);
	//AddEdge(3,5,v);
	AddEdge(4,2,v);
	//AddEdge(4,5,v);
	//AddEdge(5,4,v);
	//AddEdge(5,3,v);
	if(IsPathExcist(5,4,v,5))
		cout<<"T"<<endl;
	else
		cout<<"No"<<endl;
}