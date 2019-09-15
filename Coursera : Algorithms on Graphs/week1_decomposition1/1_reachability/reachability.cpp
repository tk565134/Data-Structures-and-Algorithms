#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool DFS(vector<vector<int>> &adj,vector<int> &visited,int u,int v){
    if(v==u) return true;
    bool ans = false;
    int s = adj[u].size();
    for(int i=0;i<s;i++){
        if(visited[adj[u][i]]==0){
            visited[adj[u][i]]=1;
            //std::cout<<adj[u][i]<<"\n";
            ans = ans or DFS(adj,visited,adj[u][i],v);
        }
    }
    return ans;

}
int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
    int n = adj.size();
    vector<int> visited(n,0);
    if(DFS(adj,visited,x,y)) return 1;
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
