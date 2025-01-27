#include "depthfirstsearch.h"
#include <algorithm>
#include <iostream>

std::vector<std::pair<int, int>> DepthFirstSearch::SpanningTree(
    int vertices, const Graph &adjacencylist)
{
  spanningtree.clear();
  parent = std::vector<int>(vertices, -1);
  DFS(std::uniform_int_distribution<int>(0, vertices - 1)(generator),//随机顶点
      adjacencylist);
  return spanningtree;
}

void DepthFirstSearch::DFS(int vertex, const Graph &adjacencylist)
{
  std::vector<int> nodeorder(adjacencylist[vertex].size());
  std::iota(nodeorder.begin(), nodeorder.end(), 0);//用一个从value递增的数列给[first, last)的容器赋值
  shuffle(nodeorder.begin(), nodeorder.end(), generator); //打乱重排

  for (auto index : nodeorder)
  {
    int nextvertex = std::get<0>(adjacencylist[vertex][index]);
    if (nextvertex < 0 or parent[nextvertex] >= 0)
      continue;
    spanningtree.push_back({vertex, nextvertex});//存放的是 格子
    parent[nextvertex] = vertex;
    DFS(nextvertex, adjacencylist);
  }
}

std::vector<int> DepthFirstSearch::Solve(int vertices,
                                         const Graph &adjacencylist,
                                         int startvertex)
{
  spanningtree.clear();
  parent = std::vector<int>(vertices, -1);
  parent[startvertex] = startvertex;
  DFS(startvertex, adjacencylist);
  return parent;
}
