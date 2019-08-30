#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
const int N = 1e6;
int arr[N];
const int V=301;
    list<int> *adj;     
bool BFS(int x, int y) 
{ 
    
    bool *visited = new bool[301]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    list<int> queue; 
    visited[x] = true; 
    queue.push_back(x); 
    list<int>::iterator i; 
    while (!queue.empty()) 
    { 
        x = queue.front(); 
        queue.pop_front(); 
        for (i = adj[x].begin(); i != adj[x].end(); ++i) 
        { 
            if (*i == y) 
                return true;
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
    return false; 
} 
int main()
{
   adj = new list<int>[V]; 
  // ios::sync_with_stdio(false);
  // cin.tie(0);
   int n,m,q;
   int x,y;
   cin >> n>>m>>q;
   for(int i = 0 ; i<m;++i)
{
   cin>>x>>y;
   adj[x].push_back(y); 
}
  for(int i = 0 ; i<q;++i)
{
cin>>x>>y;
if(BFS(x,y)) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
 
}
