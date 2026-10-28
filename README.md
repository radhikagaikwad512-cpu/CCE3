Campus Route Finder Using C++

Project Overview

The Campus Route Finder is a C++ console-based application that helps users navigate between different locations on a college campus. It represents campus locations as vertices (nodes) and roads connecting them as edges in a weighted graph.

The application uses graph algorithms such as Dijkstra's Algorithm, Breadth-First Search (BFS), and Depth-First Search (DFS) to find the shortest route and traverse connected campus locations.

The distance between locations is measured in metres, and all roads are considered bidirectional.

Objectives

Represent campus locations and roads using a graph data structure.
Find the shortest distance between two campus locations.
Display all available campus locations and road connections.
Traverse the campus graph using BFS and DFS.
Search for a campus location by its name.
Demonstrate the practical application of graph algorithms in route planning.

Features

Display Campus Places: Shows all campus locations with their unique IDs.
Display Road Connections: Lists connected locations and the distances between them.
Shortest Route Finder: Calculates the shortest distance and displays the route between two locations using Dijkstra's algorithm.
BFS Traversal: Visits reachable locations level by level using a queue.
DFS Traversal: Explores reachable locations using recursion.
Search by Place Name: Finds a location by name, ignoring letter case.
Input Validation: Handles invalid menu choices, incorrect numeric input, and invalid place IDs.

Campus Locations

The project uses six example campus locations:

ID	Campus Location
0	MainGate
1	Library
2	Canteen
3	ECEBlock
4	Auditorium
5	Hostel

Technologies Used
Programming Language: C++
Concepts: Object-Oriented Programming (OOP), Graphs, Arrays, Recursion, Queues
Algorithms: Dijkstra's Algorithm, BFS, DFS
Libraries: iostream, string, algorithm, cctype, limits

Algorithms Used

1. Dijkstra's Algorithm

Dijkstra's algorithm finds the minimum-distance path between a source and a destination in a graph with non-negative edge weights.

In this project, it calculates the shortest campus route using road distances measured in metres.

2. Breadth-First Search (BFS)

BFS explores reachable locations level by level, using a queue to manage the traversal order.

It is useful for exploring the connectivity of the campus graph. Since the graph has weighted roads, BFS does not necessarily find the shortest-distance route.

3. Depth-First Search (DFS)

DFS explores one path as deeply as possible before backtracking. This implementation uses recursion to visit connected locations.

It helps demonstrate graph traversal and connectivity.

How It Works-

Campus locations are stored as graph vertices.
Roads are represented by weighted edges containing distances in metres.
Each road is bidirectional, so travel is possible in both directions.
The user selects an operation from the menu.
The program executes the corresponding graph algorithm or search operation.
Results are displayed in the console.

Getting Started
Prerequisites

Install a C++ compiler, such as:

GCC / G++
MinGW-w64 for Windows
Clang

A compiler supporting C++11 or later is required.

Installation

Step 1: Clone the repository

bash
git clone <your-repository-url>


Replace <your-repository-url> with your actual GitHub repository URL.

Step 2: Navigate to the project directory

bash
cd <your-project-folder>


Step 3: Compile the program

bash
g++ -std=c++11 campus.cpp -o campus


Step 4: Run the program

On Linux or macOS:

bash
./campus


On Windows:

bash
campus.exe

Application Menu

When the program starts, the following menu is displayed:

text
===== CAMPUS ROUTE FINDER =====
1. Display places
2. Display road connections
3. Find shortest route
4. Show BFS traversal
5. Show DFS traversal
6. Search place by name
0. Exit

Enter choice:


Enter the number corresponding to the operation you want to perform.

Example Output-

Finding the Shortest Route

Suppose the user selects option 3, enters source ID 0 (MainGate), and destination ID 5 (Hostel).

text
Shortest distance: 800 metres
Route: MainGate -> Canteen -> Hostel


The shortest route is:

MainGate → Canteen: 300 metres
Canteen → Hostel: 550 metres

Total distance: 850 metres.

Note: The correct shortest distance for the sample graph is 850 metres, not 800 metres. The route shown above has a total distance of 850 metres.

Project Structure

text
Campus-Route-Finder/
├── campus.cpp
└── README.md

campus.cpp — Contains the complete C++ implementation.
README.md — Provides project documentation, setup instructions, and usage information.

Time Complexity-

Let 
𝑉
 represent the number of campus locations and 
𝐸
 represent the number of roads.

Algorithm / Operation	Time Complexity
Display places	
𝑂
(
𝑉
)

Display road connections	
𝑂
(
𝑉
2
)

Dijkstra's algorithm (adjacency matrix)	
𝑂
(
𝑉
2
)

BFS (adjacency matrix)	
𝑂
(
𝑉
2
)

DFS (adjacency matrix)	
𝑂
(
𝑉
2
)

Search by place name	
𝑂
(
𝑉
)
, excluding string-comparison costs

The implementation uses an adjacency matrix, making it suitable for a small campus graph.

Future Enhancements

Add more campus locations dynamically.
Allow users to add or remove roads.
Display the entire campus network graphically.
Support location names containing spaces.
Provide estimated travel time based on walking speed.
Add a graphical user interface (GUI).
Store campus locations and road information in a file or database.
Support multiple routes and alternative path suggestions.

Learning Outcomes

Through this project, users can understand:
Graph representation using an adjacency matrix.
The practical use of Dijkstra's shortest-path algorithm.
Graph traversal using BFS and DFS.
Object-oriented programming in C++.
Input validation and basic error handling.
Applying data structures and algorithms to a real-world navigation problem.
