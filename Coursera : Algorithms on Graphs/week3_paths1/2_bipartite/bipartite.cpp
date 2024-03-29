#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  vector<int> c(n,-1);
  queue<int> q;
  // for every connected component
  for(int i=0;i<n;i++){
    if(c[i]==-1){
      q.push(i);
      c[i]=0;
      // do BFS
      while(!q.empty()){
        int v = q.front();
        q.pop();
        int x = adj[v].size();
        for(int j=0;j<x;j++){
          if(c[adj[v][j]]==-1){
            // set color of unvisited vertex be the opposite color of the parent 
            c[adj[v][j]]=c[v]^1;
            q.push(adj[v][j]);
          }
          if(c[v]==c[adj[v][j]]) return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
