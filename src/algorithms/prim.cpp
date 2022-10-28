#include "prim.h"
#include <algorithm>
// 普里姆算法 https://baike.baidu.com/item/Prim/10242166?fromModule=lemma_inlink&fromtitle=%E6%99%AE%E9%87%8C%E5%A7%86%E7%AE%97%E6%B3%95&fromid=4255724
std::vector<std::pair<int, int>> Prim::SpanningTree(
    int vertices, const Graph &adjacencylist)
{
  spanningtree.clear();

  PrimAlgorithm(vertices, adjacencylist);
  return spanningtree;
}

void Prim::PrimAlgorithm(int vertices, const Graph &adjacencylist)
{
  std::vector<bool> visited(vertices, false);
  std::vector<std::pair<int, int>> boundary;
  int vertex = std::uniform_int_distribution<int>(0, vertices - 1)(generator);

  for (int i = 1; i < vertices; ++i)
  {
    visited[vertex] = true;
    for (auto p : adjacencylist[vertex])
    {
      if (std::get<0>(p) != -1 and !visited[std::get<0>(p)])
        boundary.push_back({vertex, std::get<0>(p)});
    }

    std::pair<int, int> nextedge = {-1, -1};
    do
    {
      int index =
          std::uniform_int_distribution<int>(0, boundary.size() - 1)(generator);
      std::swap(boundary[index], boundary.back());
      if (!visited[boundary.back().second])
        nextedge = boundary.back();
      boundary.pop_back();
    } while (nextedge.first == -1);

    spanningtree.push_back(nextedge);
    vertex = nextedge.second;
  }
}
