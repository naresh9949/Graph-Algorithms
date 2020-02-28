#include<iostream>
#include<vector>
using namespace std;
bool DFS_cycle(std::vector<int> v[],int s,int visited[],int parent,std::vector<int> &c);
void AddEdge(int source,int destination,vector<int> v[])
{
	v[source].push_back(destination);
}

bool IsCycle(std::vector<int> v[],int n,std::vector<int> &c)
{
	int visited[n+1];
	memset(visited,0,sizeof(visited));
	return DFS_cycle(v,1,visited,-1,c);

}

bool DFS_cycle(std::vector<int> v[],int s,int visited[],int parent,std::vector<int> &c)
{
	visited[s]=1;
	c.push_back(s);
	//cout<<s<<" ";
	std::vector<int> ::iterator it;
	for(it=v[s].begin();it!=v[s].end();it++)
	{
		if(visited[*it]==0){
			return DFS_cycle(v,*it,visited,s,c);
		}
		else if(*it!=parent){
			c.push_back(*it);
			//cout<<*it<<endl;
			return 1;
		}
	}
	return 0;
}
int main()
{
	std::vector<int> v[6],c;
	int k,m;
	std::vector<int>::iterator it;
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
	if(IsCycle(v,5,c))
	{
		cout<<"Yes"<<endl;
		it=c.end();
		cout<<*it<<" ";
		k=*it;
		it--;
		while(k!=*it)
		{
			cout<<*it<<" ";
			*it--;
		}
		cout<<endl;
		for(it=c.begin();it!=c.end();it++)
			cout<<*it<<" ";
		cout<<endl;
		for(it=c.end();it!=c.begin();it--)
			cout<<*it<<" ";
		cout<<endl;
	}
	else
		cout<<"No"<<endl;
}