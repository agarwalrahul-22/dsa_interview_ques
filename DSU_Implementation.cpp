#include<bits/stdc++.h>
using namespace std;

vector<int> rank;
vector<int> parent;

int findparent(int a){
  if(parent[a] == a) return parent[a];
  return parent[a] = findParent(parent[a]);
}

bool addToSet(int a, int b){
  a = findParent(parent[a]);
  b = findParent(parent[b]);
  if(a == b) return false;
  else{
    if(rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    rank[a] += rank[b];
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  rank.resize(n);
  parent.resize(n);
  for(int i=0;i<n;++i){
    rank[i] = 1;
    parent[i] = i;
  }
}
