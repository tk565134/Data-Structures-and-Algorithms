#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
bool negative_cycle_src(vector<vector<int> > &adj, vector<vector<int> > &cost,int src,vector<int> & dist){
  int n = adj.size();
  for(int i=0;i<n;i++){
    dist[i]=INT_MAX;
  }
  dist[src]=0;
  for(int k=0;k<n-1;k++){
    for(int i=0;i<n;i++){
      int x = adj[i].size();
      for(int j=0;j<x;j++){
        if(dist[i]!=INT_MAX){
          if(dist[adj[i][j]]>dist[i]+cost[i][j]) dist[adj[i][j]]=dist[i]+cost[i][j];
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    int x = adj[i].size();
    for(int j=0;j<x;j++){
      if(dist[i]!=INT_MAX and dist[adj[i][j]]>dist[i]+cost[i][j]) return true;
    }
  }
  return false;
}
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int n = adj.size();
  vector<int> visited(n,0);
  vector<int> dist(n,INT_MAX);
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      visited[i]=1;
      if(negative_cycle_src(adj,cost,i,dist)) return 1;
    }
    for(int j=0;j<n;j++){
      if(dist[j]!=INT_MAX) visited[j]=1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
