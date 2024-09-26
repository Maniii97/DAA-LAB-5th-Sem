#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int N;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& adjList, vector<int>& parent) {
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // slight optimization
        if (dis > dist[node]) continue;

        for (auto adj : adjList[node]) {
            int adjNode = adj.first;
            int adjDis = adj.second;
            if (dist[node] + adjDis < dist[adjNode]) {
                dist[adjNode] = dist[node] + adjDis;
                parent[adjNode] = node; 
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

vector<int> traceShortestPath(int src, int dest, vector<int>& parent) {
    vector<int> path;
    int node = dest;
    while (node != src) {
        if (parent[node] == -1) return {}; 
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int source;
    cout << "Enter the number of nodes" << endl;
    cin >> N;
    cout << "Enter source node" << endl;
    cin >> source;
    source--;

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));
    cout << "Reading the adj Matrix from the adjMatrix File" << endl;
    ifstream inputFile("adjMatrix.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> adjMatrix[i][j];
        }
    }

    vector<vector<pair<int, int>>> adjList(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjMatrix[i][j] != 0) {
                adjList[i].push_back({j, adjMatrix[i][j]});
            }
        }
    }

    cout << "Source\t\tDestination\tCost\tPath" << endl;
    
    vector<int> parent(N, -1); 
    vector<int> dist = dijkstra(source, adjList, parent);
    
    for (int i = 0; i < N; i++) {
        cout << source + 1 << "\t\t" << i + 1 << "\t\t";
        
        if (dist[i] == INT_MAX) {
            cout << "Unreachable\t-";
        } else {
            cout << dist[i] << "\t";
            vector<int> path = traceShortestPath(source, i, parent);
            if (path.empty()) {
                cout << "-";
            } else {
                for (auto node : path) {
                    cout << node + 1;
                    if (node != path.back()) cout << "->";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
