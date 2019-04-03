#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

class Edge {
public:
  Edge(int v, int w, int weight) {
    this->v = v;
    this->w = w;
    this->weight = weight;
  }
  int either(){
    return v;
  }
  int other(int v) {
    if (v == this->v) return this->w;
    else return this->v;
  }
  int weight;
  int v;
  int w;
};

auto cmp = [](Edge* left, Edge* right){ return left->weight > right->weight; };
priority_queue<Edge*, vector<Edge*>, decltype(cmp)> pq(cmp);
vector<Edge*> mst;
vector<bool> marked;

void visit(vector<vector<Edge*>>& adj, int v) {
  vector<Edge*> edges = adj[v];
  marked[v] = true;
  for (auto e : edges) {
    if (!marked[e->other(v)])
      pq.push(e);
  }
}

int main() {
  int V = 0, E = 0, root = 1;
  vector<vector<Edge*> > adj;
  scanf("%d", &V);
  scanf("%d", &E);
  scanf("%d", &root);
  for (int i = 0; i < V+1; ++i) {
    vector<Edge*> v;
    adj.push_back(v);
  }
  for (int i = 0; i < E; ++i) {
    int v, w, weight;
    scanf("%d%d%d", &v, &w, &weight);
    Edge* e = new Edge(v, w, weight);
    adj[v].push_back(e);
    adj[w].push_back(e); 
  }
  for (int i = 0; i < V+1; ++i) {
    marked.push_back(false);
  }
  visit(adj, root);
  while (!pq.empty()) {
    Edge* e = pq.top();
    pq.pop();
    int v = e->either();
    int w = e->other(v);
    if (marked[v] && marked[w]) continue;
    mst.push_back(e);
    if (!marked[v]) visit(adj, v);
    if (!marked[w]) visit(adj, w);
  }
  int max_weight = 0;
  for (auto e : mst) {
    max_weight = max(max_weight, e->weight);
  }
  cout << max_weight << endl;
  return 0;
}