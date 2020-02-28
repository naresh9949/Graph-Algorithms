#include <iostream>
#include<queue>
//#define INT_MAX 2147483647
using namespace std;

void AddEdge(int s,int e,int w,vector< pair<int,int> > v[])
{
    pair<int,int> p,p1;
    p.first=-w;
    p.second=e;
   
    p1.first=-w;
    p1.second=s;
    v[s].push_back(p);
    v[e].push_back(p1);
}
int Weight(int parent,int child,vector< pair<int,int> > v[])
{
     vector< pair<int,int> > :: iterator it;
    for(it=v[parent].begin();it!=v[parent].end();it++){
       
        pair<int,int> u;
        u=*it;
        if(u.second==child)
            return (-1*u.first);
       
    }
    return 0;
}
void Prims_Algorithm(vector< pair<int,int> > v[],int n,int vertex)
{
    bool inMST[n+1];
    int Parent[n+1];
    int Key[n+1];
    for(int i=0;i<n+1;i++)
        Key[i]=INT_MAX;
    priority_queue< pair<int ,int> > pq;
   
    pair<int,int> p;
    p.first=0;
    p.second=vertex;
    pq.push(p);
   
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        inMST[p.second]=1;
       
        vector< pair<int,int> > :: iterator it;
        for(it=v[p.second].begin();it!=v[p.second].end();it++)
        {
            pair<int,int> u;
            u=*it;
            int w=Weight(p.second,u.second,v);
            if(inMST[u.second]==0 && Key[u.second]>w)
            {
                Key[u.second]=w;
                pair<int,int> b;
                b.first=-w;
                b.second=u.second;
                pq.push(b);
                Parent[u.second]=p.second;
            }
        }
       
       
    }
   
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<"-"<<Parent[i]<<endl;
    }
   
}

int main()
{
    int n=6;
    vector< pair<int,int> > v[n+1];
    AddEdge(1,2,1,v);
    AddEdge(1,4,2,v);
    AddEdge(2,4,3,v);
    AddEdge(2,3,2,v);
    AddEdge(3,4,3,v);
    AddEdge(4,5,8,v);
    AddEdge(4,6,4,v);
    AddEdge(5,6,3,v);
   
    Prims_Algorithm(v,n,1);
   
}
