#include "pathfinding.h"
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>

// Helper function to calculate the heuristic (Manhattan distance)
int calculateHeuristic(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Helper function to check if a point is within the grid bounds
bool isValid(const Point& p, const std::vector<std::vector<int>>& grid) {
    return p.x >= 0 && p.y >= 0 && static_cast<size_t>(p.x) < grid.size() && static_cast<size_t>(p.y) < grid[0].size();
}

// Helper function to check if a point is an obstacle
bool isObstacle(const Point& p, const std::vector<std::vector<int>>& grid) {
    return grid[p.x][p.y] == 1; // Assuming 1 represents an obstacle
}

// A* Algorithm Implementation
std::vector<Point> findPath(const Point& start, const Point& goal, const std::vector<std::vector<int>>& grid) {
    // Priority queue for open nodes (sorted by fCost)
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;

    // Map to store the cost of each node
    std::unordered_map<Point, int, std::hash<Point>> gCosts;

    // Map to store the parent of each node
    std::unordered_map<Point, Point, std::hash<Point>> parents;

    // Initialize start node
    Node startNode{ start, 0, calculateHeuristic(start, goal) };
    openSet.push(startNode);
    gCosts[start] = 0;

    // Directions for moving in 4-connected grid (up, down, left, right)
    const std::vector<Point> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!openSet.empty()) {
        // Get the node with the lowest fCost
        Node current = openSet.top();
        openSet.pop();

        // Check if we've reached the goal
        if (current.point.x == goal.x && current.point.y == goal.y) {
            // Reconstruct the path
            std::vector<Point> path;
            Point node = goal;
            while (node.x != start.x || node.y != start.y) {
                path.push_back(node);
                node = parents[node];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors
        for (const auto& dir : directions) {
            Point neighbor{ current.point.x + dir.x, current.point.y + dir.y };

            // Skip if neighbor is out of bounds or an obstacle
            if (!isValid(neighbor, grid) || isObstacle(neighbor, grid)) {
                continue;
            }

            // Calculate tentative gCost
            int tentativeGCost = gCosts[current.point] + 1;

            // If this path to the neighbor is better, update the neighbor
            if (!gCosts.count(neighbor) || tentativeGCost < gCosts[neighbor]) {
                gCosts[neighbor] = tentativeGCost;
                int hCost = calculateHeuristic(neighbor, goal);
                Node neighborNode{ neighbor, tentativeGCost, hCost };
                openSet.push(neighborNode);
                parents[neighbor] = current.point;
            }
        }
    }

    // If no path is found, return an empty vector
    return {};
}