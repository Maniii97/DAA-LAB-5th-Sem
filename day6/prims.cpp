#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ifstream inputFile("inUnAdjMat.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    inputFile >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> adjMatrix[i][j];
        }
    }
    inputFile.close();

    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j]) {
                adjList[i].push_back({j, adjMatrix[i][j]});
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n, 0);
    vector<pair<pair<int, int>, int>> mst;
    pq.push({0, {0, -1}});
    int sum = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int node = top.second.first;
        int parent = top.second.second;
        int weight = top.first;

        if (vis[node]) continue;
        vis[node] = 1;

        if (parent != -1) {
            cout<<"Edge: "<<char(parent+'a')<<"--"<<char(node+'a')<<" Weight: "<<weight<<endl;
            mst.push_back({{parent, node}, weight});
        }
        sum += weight;
        for (auto i : adjList[node]) {
            int adjNode = i.first;
            int adjWeight = i.second;
            if (!vis[adjNode]) {
                pq.push({adjWeight, {adjNode, node}});
            }
        }
    }

    vector<vector<int>> mstMatrix(n, vector<int>(n, 0));
    for (auto i : mst) {
        mstMatrix[i.first.first][i.first.second] = i.second;
        mstMatrix[i.first.second][i.first.first] = i.second;
    }

    cout << "The Minimum Spanning Tree is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mstMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Total cost of the Minimum Spanning Tree: " << sum << endl;

    return 0;
}