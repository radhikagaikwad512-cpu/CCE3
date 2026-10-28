
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

const int MAX_NODES = 10;
const int INF = 1000000;

class CampusGraph {
private:
    string names[MAX_NODES];
    int cost[MAX_NODES][MAX_NODES];
    int n;

    string toLowerCase(string text) {
        transform(text.begin(), text.end(), text.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));
            });
        return text;
    }

    int findIndex(const string& target) {
        for (int i = 0; i < n; i++) {
            if (toLowerCase(names[i]) == toLowerCase(target))
                return i;
        }
        return -1;
    }

public:
    CampusGraph(int count) {
        n = (count >= 1 && count <= MAX_NODES) ? count : 0;

        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                cost[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    bool isValidIndex(int index) const {
        return index >= 0 && index < n;
    }

    void setPlace(int index, const string& place) {
        if (isValidIndex(index) && !place.empty()) {
            names[index] = place;
        }
    }

    void addRoad(int u, int v, int distance) {
        if (isValidIndex(u) && isValidIndex(v) &&
            u != v && distance > 0 && distance < INF) {
            cost[u][v] = distance;
            cost[v][u] = distance;
        } else {
            cout << "Invalid road details.\n";
        }
    }

    void showPlaces() {
        cout << "\nCampus places:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " - " << names[i] << "\n";
        }
    }

    void showConnections() {
        cout << "\nRoad connections (distance in metres):\n";
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (cost[i][j] != INF) {
                    cout << names[i] << " <-> " << names[j]
                         << " : " << cost[i][j] << " m\n";
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "No road connections available.\n";
        }
    }

    void shortestPath(int source, int destination) {
        if (!isValidIndex(source) || !isValidIndex(destination)) {
            cout << "Invalid place ID.\n";
            return;
        }

        int dist[MAX_NODES], parent[MAX_NODES];
        bool visited[MAX_NODES] = {false};

        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            parent[i] = -1;
        }

        dist[source] = 0;

        // Dijkstra's algorithm
        for (int count = 0; count < n; count++) {
            int u = -1;
            int best = INF;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < best) {
                    best = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] &&
                    cost[u][v] != INF &&
                    dist[u] != INF &&
                    dist[u] + cost[u][v] < dist[v]) {

                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "No route is available between these places.\n";
            return;
        }

        int path[MAX_NODES];
        int length = 0;

        for (int current = destination;
             current != -1;
             current = parent[current]) {
            path[length++] = current;
        }

        cout << "\nShortest distance: "
             << dist[destination] << " metres\n";

        cout << "Route: ";
        for (int i = length - 1; i >= 0; i--) {
            cout << names[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\n";
    }

    void breadthFirstSearch(int start) {
        if (!isValidIndex(start)) {
            cout << "Invalid place ID.\n";
            return;
        }

        bool visited[MAX_NODES] = {false};
        int queue[MAX_NODES];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS traversal: ";

        while (front < rear) {
            int u = queue[front++];
            cout << names[u] << " ";

            for (int v = 0; v < n; v++) {
                if (cost[u][v] != INF &&
                    u != v && !visited[v]) {
                    visited[v] = true;
                    queue[rear++] = v;
                }
            }
        }

        cout << "\n";
    }

    void depthFirstSearchHelper(int u, bool visited[]) {
        visited[u] = true;
        cout << names[u] << " ";

        for (int v = 0; v < n; v++) {
            if (cost[u][v] != INF &&
                u != v && !visited[v]) {
                depthFirstSearchHelper(v, visited);
            }
        }
    }

    void depthFirstSearch(int start) {
        if (!isValidIndex(start)) {
            cout << "Invalid place ID.\n";
            return;
        }

        bool visited[MAX_NODES] = {false};

        cout << "DFS traversal: ";
        depthFirstSearchHelper(start, visited);
        cout << "\n";
    }

    void findPlaceByName(const string& target) {
        int index = findIndex(target);

        if (index == -1) {
            cout << "Place not found. Check spelling.\n";
        } else {
            cout << "Place found: " << names[index]
                 << " (ID " << index << ")\n";
        }
    }
};

// Reads an integer safely without leaving cin in a failed state.
bool readInteger(const string& prompt, int& value) {
    cout << prompt;

    if (cin >> value) {
        return true;
    }

    if (cin.eof()) {
        return false;
    }

    cout << "Invalid input. Please enter a number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

int main() {
    CampusGraph campus(6);

    campus.setPlace(0, "MainGate");
    campus.setPlace(1, "Library");
    campus.setPlace(2, "Canteen");
    campus.setPlace(3, "ECEBlock");
    campus.setPlace(4, "Auditorium");
    campus.setPlace(5, "Hostel");

    // Bidirectional roads with distances in metres
    campus.addRoad(0, 1, 200);
    campus.addRoad(0, 2, 300);
    campus.addRoad(1, 2, 100);
    campus.addRoad(1, 3, 250);
    campus.addRoad(2, 3, 150);
    campus.addRoad(3, 4, 200);
    campus.addRoad(4, 5, 350);
    campus.addRoad(2, 5, 550);

    int choice;

    do {
        cout << "\n===== CAMPUS ROUTE FINDER =====\n";
        cout << "1. Display places\n";
        cout << "2. Display road connections\n";
        cout << "3. Find shortest route\n";
        cout << "4. Show BFS traversal\n";
        cout << "5. Show DFS traversal\n";
        cout << "6. Search place by name\n";
        cout << "0. Exit\n";

        if (!readInteger("Enter choice: ", choice)) {
            cout << "\nInput ended. Exiting program.\n";
            break;
        }

        switch (choice) {
            case 1:
                campus.showPlaces();
                break;

            case 2:
                campus.showConnections();
                break;

            case 3: {
                int source, destination;
                campus.showPlaces();

                if (!readInteger("Enter source ID: ", source))
                    return 0;

                if (!readInteger("Enter destination ID: ", destination))
                    return 0;

                campus.shortestPath(source, destination);
                break;
            }

            case 4:
            case 5: {
                int start;
                campus.showPlaces();

                if (!readInteger("Enter starting place ID: ", start))
                    return 0;

                if (choice == 4) {
                    campus.breadthFirstSearch(start);
                } else {
                    campus.depthFirstSearch(start);
                }
                break;
            }

            case 6: {
                string target;
                cout << "Enter place name: ";

                if (!(cin >> target)) {
                    cout << "\nInput ended. Exiting program.\n";
                    return 0;
                }

                campus.findPlaceByName(target);
                break;
            }

            case 0:
                cout << "Thank you for using Campus Route Finder.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
