#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int K = 1e5 + 900;
//double rounded = (int)(num * 1000.0) / 1000.0;
int n;
vector<vector<int>> adj;    // adjacency matrix of graph
const int INF = 1000000000; // weight INF means there is no edge

struct Edge
{
   int w = INF, to = -1;
};

void prim()
{
   int total_weight = 0;
   vector<bool> selected(n, false);
   vector<Edge> min_e(n);
   min_e[0].w = 0;

   for (int i = 0; i < n; ++i)
   {
      int v = -1;
      for (int l = 0; l < n; ++l)
         cout << min_e[l].w << " " << min_e[l].to << "    ";
      cout << endl;
      for (int j = 0; j < n; ++j)
      {
         if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
            v = j;
      }

      if (min_e[v].w == INF)
      {
         cout << "No MST!" << endl;
         exit(0);
      }

      selected[v] = true;
      total_weight += min_e[v].w;
      if (min_e[v].to != -1)
         cout << v << " " << min_e[v].to << endl;

      for (int to = 0; to < n; ++to)
      {
       
         if (adj[v][to] < min_e[to].w)
            min_e[to] = {adj[v][to], v};
      }
   }

   cout << total_weight << endl;
}
int main()
{

   ios::sync_with_stdio(false);
   cin.tie(0);
   n = 6;
   adj = {
       {INF, 2, INF, 1, 4, INF},
       {2, INF, 3, 3, INF, 7},
       {INF, 3, INF, 5, INF, 8},
       {1, 3, 5, INF, 9, INF},
       {4, INF, INF, 9, INF, INF},
       {INF, 7, 8, INF, INF, INF}};
   for (int i = 0; i < 6; ++i)
   {
      for (int j = 0; j < 6; ++j)
      {
         cout << adj[j][i] << " ";
         if (adj[j][i] != INF)
            cout << "         ";
      }
      cout << endl;
   }

   prim();
}
