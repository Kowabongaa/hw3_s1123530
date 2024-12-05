//Alvin s1123530 12/7/2024
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyList(int V, const vector<pair<int, int>> &edges) 
{
    vector<vector<int>> adj(V); 
    for (auto edge : edges) 
    {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void printAdjacencyList(const vector<vector<int>> &adj) 
{
    cout << "[";
    for (int i = 0; i < adj.size(); ++i) 
    {
        cout << "[";
        for (int j = 0; j < adj[i].size(); ++j) 
        {
            cout << adj[i][j];
            if (j != adj[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != adj.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() 
{
    int V, E;
    
    cout << "V: ";
    cin >> V;
    cout << "E: ";
    cin >> E;

    vector<pair<int, int>> edges;

    //enter every edge to enter the next edge
    cout << "Input edges (u v):" << endl;
    for (int i = 0; i < E; ++i) 
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= V || v < 0 || v >= V) 
        {
            cerr << "Invalid edge (" << u << ", " << v << "). Please enter vertices in range [0, " << V - 1 << "]." << endl;
            --i;
            continue;
        }
        edges.push_back({u, v});
    }

    vector<vector<int>> adj = createAdjacencyList(V, edges);
    cout << "Adjacency List:" << endl;
    printAdjacencyList(adj);
    return 0;
}
