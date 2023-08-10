//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> num[]) {
        
        // Code here
    std::vector<int> vis(n, 0);
    std::queue<int> inox;

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            inox.push(i);
            vis[i] = 1;

            while (inox.size())
            {
                int local = inox.front();
                inox.pop();

                int count = 0;
                for (auto i : num[local])
                {
                    if (vis[i] == 0)
                    {
                        vis[i] = 1;
                        inox.push(i);
                    }
                    else
                        count++;
                }

                if (count > 1)
                    ok = true;
            }
        }
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