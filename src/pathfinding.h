#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include <queue>
#include <set>
#include <functional>

// Defining Point(x,y) for grid coordinates
struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
};

// Custom hash function for unordered_map
namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& p) const noexcept {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
}

// Node structure for A* Algorithm
struct Node {
    Point point;
    int gCost;
    int hCost;

    int fCost() const {
        return gCost + hCost;
    }

    bool operator>(const Node& other) const {
        return fCost() > other.fCost();
    }
};

// Pathfinding function (A* algorithm)
std::vector<Point> findPath(const Point& start, const Point& goal, const std::vector<std::vector<int>>& grid);

#endif 


