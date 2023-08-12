//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool traverse(std::vector<int> num[], int n, std::vector<int> &vis, std::vector<int> &path, int index)
{
    vis[index] = 1;
    path[index] = 1;

    for (auto i : num[index])
    {
        if (vis[i] == 0)
        {
            if (traverse(num, n, vis, path, i))
                return true;
        }
        else if (path[i])
            return true;
    }

    path[index] = 0;
    return false;
}

    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> num[]) {
        // code here
        
    std::vector<int> vis(n, 0), path(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (traverse(num, n, vis, path, i))
                return true;
        }
    }

    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends