#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
void set_shortest(int x,vector<int> &shortest,vector<vector<int>> &adj){
  shortest[x]=0;
  int n = adj[x].size();
  for(int i=0;i<n;i++){
    if(shortest[adj[x][i]]==1){
      set_shortest(adj[x][i],shortest,adj);
    }
  }
}
void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  int n = adj.size();
  distance[s]=0;
  reachable[s]=1;
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
      int x = adj[j].size();
      for(int k=0;k<x;k++){
        if(distance[j]!=std::numeric_limits<long long>::max()){
          if(distance[j]+cost[j][k]<distance[adj[j][k]]){
            distance[adj[j][k]]=cost[j][k]+distance[j];
            reachable[adj[j][k]]=1;
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    int x = adj[i].size();
    for(int j=0;j<x;j++){
      if(distance[i]!=std::numeric_limits<long long>::max()){
        if(distance[i]+cost[i][j]<distance[adj[i][j]]){
          if(shortest[adj[i][j]]==1) set_shortest(adj[i][j],shortest,adj);
        }
      }
    }
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
