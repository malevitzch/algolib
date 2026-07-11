#ifndef SCC_CPP
#define SCC_CPP
#include "graph.cpp"
#include "util.cpp"

struct scc_t {
  std::vector<int> components;
  int operator[](int i) {
    return components[i-1];
  }
};

void paint(graph_t& graph, std::vector<int>& vis, int my_color, int v) {
  vis[v - 1] = my_color;
  for(int x : graph[v]) {
    if(vis[x - 1] == 0) {
      paint(graph, vis, my_color, x);
    }
  }
}

scc_t scc(graph_t& graph) {
  std::vector<int> sorted = toposort(graph);
  graph_t reversed = reverse_graph(graph);
  std::vector<int> res(graph.size(), 0);
  int index = 1;
  for(int x : sorted) {
    if(res[x - 1] == 0) {
      paint(reversed, res, index++, x);
    }
  }
  return scc_t {res};
}

#endif
