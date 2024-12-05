//Alvin s1123530 12/7/2024
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void dfsHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfsResult) 
{
    visited[node] = true; 
    dfsResult.push_back(node);

    for (int neighbor : adj[node]) 
    {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited, dfsResult);
        }
    }
}

vector<int> dfsTraversal(int V, const vector<vector<int>>& adj) 
{
    vector<int> dfsResult; 
    vector<bool> visited(V, false);
    dfsHelper(0, adj, visited, dfsResult);
    return dfsResult;
}

int main() 
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> adj(V);
    cin.ignore();
    
    for (int i = 0; i < V; ++i) 
    {
        string line;
        getline(cin, line); 
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) 
        {
            adj[i].push_back(neighbor);
        }
    }

    vector<int> dfsResult = dfsTraversal(V, adj);
    for (int node : dfsResult) 
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
