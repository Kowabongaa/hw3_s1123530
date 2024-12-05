//Alvin s1123530 12/7/2024
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int findMST(int V, vector<vector<pair<int, int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<bool> visited(V, false);
    int mstWeight = 0;

    pq.push({0, 0});

    while (!pq.empty()) 
    {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        mstWeight += weight;

        for (auto [neighbor, edgeWeight] : adj[node]) 
        {
            if (!visited[neighbor]) 
            {
                pq.push({edgeWeight, neighbor});
            }
        }
    }
    return mstWeight;
}

int main() 
{
    int V, E;
    cout << "V: ";
    cin >> V;
    cout << "E: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; ++i) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    cout << "MST Weight: " << findMST(V, adj) << endl;

    return 0;
}
