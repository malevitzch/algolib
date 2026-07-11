#ifndef LCA_CPP
#define LCA_CPP

#include "graph.cpp"
#include <array>

struct lca_t {
  static constexpr int MAX_DEPTH = 22;
  std::vector<std::array<int, MAX_DEPTH>> jmp;
  std::vector<int> depths;
  
  int depth(int v) { return depths[v - 1]; }
  int size() { return depths.size(); }
  lca_t(int size) : depths(size), jmp(size, std::array<int, MAX_DEPTH>()) {}
  int lca(int a, int b) {
    if(depth(a) < depth(b)) std::swap(a, b);
    for(int i = MAX_DEPTH - 1; i >= 0; i--)
      if(depth(jmp[a - 1][i]) >= depth(b)) a = jmp[a - 1][i];
    if(a == b) return a;
    for(int i = MAX_DEPTH - 1; i >= 0; i--)
      if(jmp[a - 1][i] != jmp[b - 1][i]) a = jmp[a - 1][i], b = jmp[b - 1][i];
    return jmp[a - 1][0];
  }
};

void lca_dfs(int node, graph_t& graph, lca_t& lca) {
  for(int x : graph[node]) {
    if(lca.jmp[x - 1][0] == 0) {
      lca.jmp[x - 1][0] = node;
      lca.depths[x - 1] = lca.depths[node] + 1;
      lca_dfs(x, graph, lca);
    }
  }
}

lca_t lca(graph_t graph, int root) {
  lca_t res(graph.size());
  res.jmp[root - 1][0] = root;
  lca_dfs(root, graph, res);
  for(int i = 1; i < lca_t::MAX_DEPTH; i++)
    for(int v : graph.nodes())
      res.jmp[v - 1][i] = res.jmp[res.jmp[v - 1][i - 1]][i - 1];
  return res;
}

#endif