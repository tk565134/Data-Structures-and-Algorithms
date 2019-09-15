#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  int n = adj.size();
  vector<int> f(n,0);
  vector<int> dis(n,INT_MAX);
  dis[s]=0;
  /*
  // with priority_queue
  priority_queue<pi, vector<pi>, greater<pi> > pq;
  for(int i=0;i<n;i++){
    pq.push(make_pair(dis[i],i));
  }
  while(!pq.empty()){
    int x = pq.top().second;
    if(x==t) break;
    f[x]=1;
    pq.pop();
    int si = adj[x].size();
    for(int i=0;i<si;i++){
      if(dis[x]!=INT_MAX and f[adj[x][i]]==0){
        if(cost[x][i]+dis[x]<dis[adj[x][i]]){
          dis[adj[x][i]]=cost[x][i]+dis[x];
          pq.push(make_pair(dis[adj[x][i]],adj[x][i]));
        }
      }
    }
  }*/

  // with maps
  map<pi,int> m;
  for(int i=0;i<n;i++){
    m[make_pair(dis[i],i)]=1;
  }
  while(!m.empty()){
    int x = m.begin()->first.second;
    if(x==t) break;
    m.erase(m.begin()->first);
    f[x]=1;
    int si = adj[x].size();
    for(int i=0;i<si;i++){
      if(dis[x]!=INT_MAX and f[adj[x][i]]==0){
        if(cost[x][i]+dis[x]<dis[adj[x][i]]){
          dis[adj[x][i]]=cost[x][i]+dis[x];
          m[make_pair(dis[adj[x][i]],adj[x][i])]=1;
        }
      }
    }
  }
  if(dis[t]==INT_MAX) return -1;
  return dis[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
