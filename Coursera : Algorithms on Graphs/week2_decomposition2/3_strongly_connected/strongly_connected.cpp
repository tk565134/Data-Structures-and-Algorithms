#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::pair;
using std::stack;

void dfs1(stack<int> &s,vector<vector<int>> &adj,int x,vector<int> &visited1){
  visited1[x]=1;
  int n = adj[x].size();
  for(int i=0;i<n;i++){
    if(visited1[adj[x][i]]==0) dfs1(s,adj,adj[x][i],visited1);
  }
  s.push(x);
  return ;
}
void dfs2(vector<vector<int>> &adj,vector<int> &visited2,int x){
  visited2[x]=1;
  int n = adj[x].size();
  for(int i=0;i<n;i++){
    if(visited2[adj[x][i]]==0) dfs2(adj,visited2,adj[x][i]);
  }
  return ;
}
int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  int n = adj.size();
  vector<int> visited1(n,0);
  stack<int> s;
  for(int i=0;i<n;i++){
    if(visited1[i]==0) dfs1(s,adj,i,visited1);
  }
  // reverse the graph
  vector<vector<int>> radj(n);
  for(int i=0;i<n;i++){
    int x = adj[i].size();
    for(int j=0;j<x;j++){
      radj[adj[i][j]].push_back(i);
    }
  }
  vector<int> visited2(n,0);
  while(!s.empty()){
    int v = s.top();
    s.pop();
    if(visited2[v]==0){
      dfs2(radj,visited2,v);
      result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
