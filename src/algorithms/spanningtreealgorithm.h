#ifndef SPANNINGTREEALGORITHM_H
#define SPANNINGTREEALGORITHM_H

#include "cellborder.h"
#include <memory>
#include <random>
#include <vector>

typedef std::tuple<int, std::shared_ptr<CellBorder>> Edge;
typedef std::vector<std::vector<Edge>> Graph;
// 生成树  抽象类，其他几个算法均继承自它
class SpanningtreeAlgorithm {
 public:
  SpanningtreeAlgorithm();
  virtual std::vector<std::pair<int, int>> SpanningTree(int, const Graph&) = 0;

 protected:
  std::vector<std::pair<int, int>> spanningtree;
  std::random_device randomdevice;//真随机数
  std::mt19937 generator;//大范围随机数生成（对比rand）
};

#endif /* end of include guard: SPANNINGTREEALGORITHM_H */
