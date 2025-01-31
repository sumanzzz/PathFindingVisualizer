#Pathfinding Algorithm Visualizer
This project implements the A* (A-star) pathfinding algorithm to find the shortest path between two points on a grid. It uses a grid-based system where some cells are blocked and others are open, allowing the user to visualize how the algorithm navigates through the grid to reach the goal.

#Features:
A Pathfinding*: The core algorithm that calculates the shortest path using a combination of the current path cost (gCost) and estimated cost to the goal (hCost).
Grid Visualization: A simple 2D grid where you can define blocked and open cells.
Path Reconstruction: Once the algorithm finds the shortest path, it reconstructs the path and displays it in the grid.
Technologies Used:
C++: For implementing the A* algorithm and the pathfinding logic.
SFML (Simple and Fast Multimedia Library): For graphical visualization and rendering of the grid.
#Setup:
Clone the repository.
Ensure you have SFML 3 installed and properly linked with the project.
Compile and run the program to visualize the A* pathfinding in action.
How to Use:
Define the start and goal points.
Set blocked cells (e.g., obstacles that the algorithm cannot pass through).
Run the program to see the algorithm in action as it calculates the shortest path from start to goal.
