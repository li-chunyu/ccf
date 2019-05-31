#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <utility>

#include <stdio.h>

using namespace std;

class Edge {
public:
  Edge(int type, int v, int w, int len) {
    v_ = v;
    w_ = w;
    if (t == 0) {
      tired = len;
    }
    if (t == 1) {
      tired_ = len * len;
    }
  }
  int either() {
    return v_;
  }
  int other(int v) {
    if (v == v_) return w_;
    else return v_;
  }
  int tired(){
    return tired_;
  }
private:
  int v_;
  int w_;
  int tired_;
}

class SP {
public:
  SP(vector<vector<Edge*> > adj, int v) {
    for (int i = 0; i < adj.size(); ++i) {
      distTo_.push_back(INT_MAX);
    }
    distTo[v] = 0;
    pq.push(make_pair(0, v));
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      relax(adj, p.second);
    }
  }
  void relax(vector<vector<Edge*> >& adj, int v) {
        for (auto e : adj[v]) {
          int w = e->other(v);
          if (distTo_[w] > distTo_[v] + e->tired()) {
            distTo_[w] = distTo_[v] + e->tired();
            edgeTo_[w] = e;
            if (contain(w)) {
              change(w, distTo_[w]);
            } else {
              pq.push(make_pair(distTo_[w], w));
            }
          }
        }
  }
  bool contain(int v) {
    for (auto ele : pq) {
      if (ele.second == v)
        return true;
    }
    return false;
  }
  void change(int v, int value) {
    for (int i = 0; i < pq.size(); ++i) {
      if (pq[i].second == v) {
        pq[i].first = value;
      }
    }
  }
private:
  vector<int> distTo_;
  vector<Edge*> edgeTo_;
  auto cmp = [](pair<int, int> p1, pair<int, int> p2) {return p1.first > p2.first;};
  priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
}

int main() {
  int V = 0, E = 0;
  vector<bool> marked;
  // start from 1.
  vector<vector<Edge*> > adj;
  //
  // init data;
  //
  for (int i = 0; i < V; ++i) {
    marked.push_back(false);
  }

}