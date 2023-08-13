//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> num[]) {
        // code here
    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : num[i])
            indeg[j]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();

        count++;
        inox.pop();

        for (auto i : num[local])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    if (count != n)
        return true;

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