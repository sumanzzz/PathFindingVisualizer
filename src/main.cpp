#include "pathfinding.h"
#include <iostream>

int main() {
    // Example grid (0 = walkable, 1 = obstacle)
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    Point start{ 0, 0 };
    Point goal{ 3, 3 };

    std::vector<Point> path = findPath(start, goal, grid);

    // Print the path
    for (const auto& p : path) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}