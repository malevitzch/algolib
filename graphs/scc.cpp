#ifndef SCC_CPP
#define SCC_CPP
#include "graph.cpp"
#include "util.cpp"

struct scc_t {
  std::vector<int> components;
  const int component_count;
  int operator[](int i) {
    return components[i-1];
  }
  scc_t(std::vector<int> components) : components(components), component_count(*std::max_element(components.begin(), components.end())) {}
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
  std::vector<int> components(graph.size(), 0);
  int index = 1;
  for(int x : sorted) {
    if(components[x - 1] == 0) {
      paint(reversed, components, index++, x);
    }
  }
  scc_t res(components);
  return res;
}

#endif
