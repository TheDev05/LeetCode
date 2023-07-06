//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
bool check(std::vector<int> num[], std::vector<int> &vis, int start)
{
    std::queue<std::pair<int, int>> qt;

    qt.push({start, -1});
    vis[start] = 1;

    bool ok = false;
    while (qt.size())
    {
        int inox = qt.front().first;
        int parent = qt.front().second;

        qt.pop();

        int count = 0;
        for (auto i : num[inox])
        {
            if (vis[i]) count++;
            else
            {
                qt.push({i, inox});
                vis[i] = 1;
            }
        }
        
        if(count > 1) ok = true;
    }

    return ok;
}

    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> num[]) {
    std::vector<int> vis(n, 0);

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
           ok |= check(num, vis, i);
    }

    return ok;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends