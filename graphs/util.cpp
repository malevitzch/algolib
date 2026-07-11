#ifndef UTIL_CPP
#define UTIL_CPP

#include <vector>
#include <algorithm>
#include "graph.cpp"

void topo_dfs(graph_t& graph, std::vector<bool>& vis, std::vector<int>& res, int v) {
  vis[v - 1] = true;
  for(int x : graph.out(v)) {
    if(!vis[x - 1]) topo_dfs(graph, vis, res, x);
  }
  res.push_back(v);
}
std::vector<int> toposort(graph_t& graph) {
  std::vector<bool> vis(graph.size());
  std::vector<int> res;
  for(int v : graph.nodes()) {
    if(!vis[v - 1]) topo_dfs(graph, vis, res, v);
  }
  std::reverse(res.begin(), res.end());
  return res;
}

graph_t reverse_graph(graph_t& graph) {
  graph_t reversed_graph(graph.size());
  for(int from : graph.nodes()) {
    for(int to : graph[from]) {
      reversed_graph.add_edge(to, from);
    }
  }
  return reversed_graph;
}

void reachable_dfs(graph_t& graph, std::vector<bool>& vis, int v) {
  vis[v] = true;
  for(int x : graph.out(v)) {
    if(!vis[x]) reachable_dfs(graph, vis, x);
  }
}
std::vector<bool> reachable(graph_t& graph, int start) {
  std::vector<bool> vis(graph.size());
  reachable_dfs(graph, vis, start);
  return vis;
}
#endif