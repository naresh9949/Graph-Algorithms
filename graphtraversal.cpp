#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
void AddEdge(vector<int> v[],int s,int d)
{
	v[s].push_back(d);
	v[d].push_back(s);
}
bool search(vector<int> v[],int s,int d)
{
	std::vector<int> ::iterator it;
	for(it=v[s].begin();it!=v[s].end();it++)
	{
		if(*it==d)
			return true;
	}
	return false;
}
void DFS(vector<int> v[])
{
	int c=0;
	vector<int> ::iterator it;
	bool visited[5];
	for(int i=0;i<5;i++)
	visited[i]=false;
	int p;
	stack<int> s;
	s.push(0);
	visited[0]=true;
	c++;
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		cout<<p<<"\t";
		for(it=v[p].begin();it!=v[p].end();it++)
		{
			if(visited[*it]==false){
				s.push(*it);
				visited[*it]=true;
				c++;
				break;
			}
		}
	}
	cout<<endl;

}
void BFS(vector<int> v[])
{
	vector<int> ::iterator it;
	bool visited[5];
	for(int i=0;i<5;i++)
		visited[i]=false;
	queue<int> q;
	int p;
	q.push(0);
	visited[0]=true;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p<<"\t";
		for(it=v[p].begin();it!=v[p].end();it++)
		{
			if(visited[*it]==false){
				q.push(*it);
				visited[*it]=true;
			}
		}


	}
	cout<<endl;
}
//For More Visite Geeksforgeeks
bool cycleuntil(int vt,vector<int> v[],int parent,bool visited[])
{
	visited[vt]=true;
	vector<int> ::iterator it;
	for(it=v[vt].begin();it!=v[vt].end();it++)
	{
		if(visited[*it]==false){
			if(cycleuntil(*it,v,vt,visited))
				return true;
		}
		else if(*it!=parent)
			return true;
	}
	return false;
}
bool iscycle(vector<int> v[])
{
	bool visited[5];
	for(int i=0;i<5;i++)
		visited[i]=false;
	for(int i=0;i<5;i++)
	{
		if(visited[i]==false)
			if(cycleuntil(i,v,-1,visited))
				return true;
	}
	return false;
}

//TO get Shortest Path
void shortest_path(vector<int> v[],int start,int destination,int n)
{
	queue<int> q;
	int visited[n],distance[n],predecesor[n],f=0;
	vector<int> ::iterator it;
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		distance[i]=INT_MAX;
		predecesor[i]=-1;
	}
	q.push(start);
	visited[start]=true;
	distance[start]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(it=v[k].begin();it!=v[k].end();it++)
		{
			if(visited[*it]==false)
			{
				visited[*it]=true;
				distance[*it]=distance[k]+1;
				predecesor[*it]=k;
				q.push(*it);
				if(*it==destination)
				{
					f=1;
					break;
				}
			}
		}
		if(f==1)
			break;
	}
	if(f==0)
		cout<<"They are not connected"<<endl;
	else
	{
		cout<<"Path Size : "<<distance[destination]<<endl;
		int p=destination;
		while(predecesor[p]!=-1)
		{
			cout<<p<<" <-- ";
			p=predecesor[p];
		}
		cout<<start<<endl;
	}
}
int main()
{
	std::vector<int> v[5];
	AddEdge(v,0,1);
	AddEdge(v,0,2);
	AddEdge(v,1,3);
	AddEdge(v,2,3);
	AddEdge(v,2,4);
	AddEdge(v,3,4);
	shortest_path(v,0,3,5);
	
}