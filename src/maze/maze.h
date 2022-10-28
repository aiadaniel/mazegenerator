#ifndef MAZE_H
#define MAZE_H

#ifndef M_PI
#define M_PI 3.1415926
#endif

#include "cellborder.h"
#include "spanningtreealgorithm.h"
#include <memory>
#include <vector>

class Maze
{
public:
    Maze(int = 0, int = 0, int = 1);
    void GenerateMaze(SpanningtreeAlgorithm *);
    void PrintMazeGnuplot(const std::string &, bool = false) const;
    void PrintMazeSVG(const std::string &, bool = false) const;
    virtual void InitialiseGraph() = 0;

protected:
    // Solving a maze is equivalent to finding a path in a graph
    int vertices_;
    Graph adjacencylist_, solution_; // 相邻区域  解决（即迷宫的正确路径）
    int startvertex_, endvertex_;

    void RemoveBorders(const std::vector<std::pair<int, int>> &);// 移除部分边，形成通道
    void Solve(const std::vector<std::pair<int, int>> &);
    virtual std::tuple<double, double, double, double> GetCoordinateBounds()
        const = 0;
};

#endif /* end of include guard: MAZE_H */
