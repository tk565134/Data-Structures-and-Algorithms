#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  int n = adj.size();
  vector<int> v(n,-1);
  queue<int> q;
  q.push(s);
  v[s]=0;
  int f=0;
  while(!q.empty()){
    int ve = q.front();
    q.pop();
    int x = adj[ve].size();
    //std::cout<<v[ve]<<"\n";
    for(int i=0;i<x;i++){
      if(v[adj[ve][i]]==-1){
        v[adj[ve][i]] = v[ve]+1;
        q.push(adj[ve][i]);
        if(adj[ve][i]==t){
          f=1;
          break;
        }
      }
    }
    if(f) break;
  }
  return v[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
