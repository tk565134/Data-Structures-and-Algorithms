#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;
int findSet(vector<vector<int>> sets,int s){
  int n = sets.size();
  for(int i=0;i<n;i++){
    int x = sets[i].size();
    for(int j=0;j<x;j++){
      if(sets[i][j]==s) return i;
    }
  }
  return 0;
}
double clustering(vector<int> x, vector<int> y, int k) {
  //write your code here
  int n = x.size();
  vector<vector<int>> sets(n);
  for(int i=0;i<n;i++){
    sets[i].push_back(i);
  }
  vector<pair<double,pair<int,int>>> edge;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double dis = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
      edge.push_back(make_pair(dis,make_pair(i,j)));
    }
  }
  sort(edge.begin(),edge.end());
  int l = edge.size();
  int subsets = n;
  for(int i=0;i<l;i++){

      pair<double,pair<int,int>> t = edge[i];
      int s1 = findSet(sets,t.second.first);
      int s2 = findSet(sets,t.second.second);
      if(s1!=s2){
        if(sets.size()==k) return t.first;
        sets[s1].insert(sets[s1].end(),sets[s2].begin(),sets[s2].end());
        sets.erase(sets.begin()+s2);
      }
  }
  return -1.;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
