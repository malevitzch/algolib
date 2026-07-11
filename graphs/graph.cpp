#ifndef GRAPH_CPP
#define GRAPH_CPP
#include <vector>
#include <numeric>

// A graph is represented by a list of n outgoing edge vector, numbered from 1 to n
struct graph_t {
  const int vertex_count;
  int size() { return vertex_count; }
  std::vector<std::vector<int>> edges;
  std::vector<int>& out(int index) { return edges[index - 1]; }
  std::vector<int>& operator[](int index) { return edges[index - 1]; }
  std::vector<int> nodes() {
    std::vector<int> v(vertex_count);
    std::iota(v.begin(), v.end(), 1);
    return v;
  }
  void add_edge(int from, int to) {
    edges[from - 1].push_back(to);
  }
  void add_edge(std::pair<int, int> e) {
    edges[e.first - 1].push_back(e.second);
  }
  graph_t(int n) : vertex_count(n), edges(std::vector<std::vector<int>>(n)) {}
  graph_t(int n, std::vector<std::pair<int, int>> edges) : vertex_count(n) {
    for(auto& e : edges) add_edge(e);
  }
};
#endif