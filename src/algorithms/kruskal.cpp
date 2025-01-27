#include "kruskal.h"
#include <algorithm>
#include <numeric>
#include <random>
// 克鲁斯卡尔算法 https://baike.baidu.com/item/%E5%85%8B%E9%B2%81%E6%96%AF%E5%8D%A1%E5%B0%94%E7%AE%97%E6%B3%95/4455899?fromtitle=Kruskal&fromid=10242089&fr=aladdin
std::vector<std::pair<int, int>> Kruskal::SpanningTree(
    int vertices, const Graph &adjacencylist)
{
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i < vertices; ++i)
  {
    for (const auto &edge : adjacencylist[i])
    {
      if (std::get<0>(edge) > i)
        edges.push_back({i, std::get<0>(edge)});
    }
  }
  shuffle(edges.begin(), edges.end(), generator);

  parent_ = std::vector<int>(vertices);
  std::iota(parent_.begin(), parent_.end(), 0);

  spanningtree.clear();
  for (const auto &edge : edges)
  {
    int u = GetParent(std::get<0>(edge)), v = GetParent(edge.second);
    if (u == v)
      continue;
    parent_[u] = v;
    spanningtree.push_back(edge);
  }
  return spanningtree;
}

int Kruskal::GetParent(int u)
{
  return (parent_[u] == u) ? u : (parent_[u] = GetParent(parent_[u]));
}
