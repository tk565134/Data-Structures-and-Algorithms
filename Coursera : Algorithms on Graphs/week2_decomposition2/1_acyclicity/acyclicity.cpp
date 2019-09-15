#include <iostream>
#include <vector>

using std::vector;
using std::pair;
bool DFS(vector<vector<int>> & adj,vector<int> &visited,int x,vector<int> & inStack){
  visited[x]=1;
  inStack[x]=1;
  int n = adj[x].size();
  for(int i=0;i<n;i++){
    //std::cout<< x << " "<<adj[x][i]<<"\n";
    if(inStack[adj[x][i]]==1) return true;
    else{
      if(DFS(adj,visited,adj[x][i],inStack))    return true;
      inStack[adj[x][i]]=0;

    }
  }
  return false;
}
int acyclic(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  // to maintain the visited nodes
  vector<int> visited(n,0);
  // to maintain the node curretly in the DFS stack
  vector<int> inStack(n,0);
  for(int i=0;i<n;i++){
    if(visited[i]==0) {
      bool ans = DFS(adj,visited,i,inStack);
      if(ans) return 1;
      inStack[i]=0;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
