#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>
#include <bits/stdc++.h>
using namespace std;
int findMin(vector<double> &v){
  int n = v.size();
  int mi=0;
  double m = v[0];
  for(int i=1;i<n;i++){
    if(v[i]<m){
      m=v[i];
      mi=i;
    }
  }
  return mi;
}
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  int n = x.size();
  vector<double> dist(n,DBL_MAX);
  vector<int> visited(n,0);
  dist[0]=0;
  for(int i=0;i<n;i++){
    int t = findMin(dist);
    result +=dist[t];
    visited[t]=1;
    dist[t]=DBL_MAX;
    for(int j=0;j<n;j++){
      if(visited[j]!=1){
        double dis = sqrt(pow(x[t]-x[j],2)+pow(y[t]-y[j],2));
        dist[j]=min(dist[j],dis);
      }
    }
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
