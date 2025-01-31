#ifndef PATHFINDING.h
#define PATHFINDING.h

#include<vector>
#include<queue>
#include<set>
#include<functional>

//defining point(x,y) for grid coordinates
struct Point {
	int x, y;
	bool operator<(const Point& other)const {
		return std::tie(x, y) < std::tie(other.x, other.y);
	}
};

//Node structure for A* Algorithm
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
//pathfinding Function (A* algorithm)
std::vector<Point>findPath(const Point& start, const Point& goal, const std::vector<std::vector<int>>& grid);
#endif

