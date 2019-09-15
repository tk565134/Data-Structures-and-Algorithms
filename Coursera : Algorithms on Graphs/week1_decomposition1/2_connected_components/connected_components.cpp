#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void DFS(vector<vector<int>> &adj,vector<int> &visited,int x){
  int s = adj[x].size();
  for(int i=0;i<s;i++){
    if(visited[adj[x][i]]==0){
      visited[adj[x][i]]=1;
      DFS(adj,visited,adj[x][i]);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  int n = adj.size();
  vector<int> visited(n,0);
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      res++;
      visited[i]=1;
      DFS(adj,visited,i);
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
