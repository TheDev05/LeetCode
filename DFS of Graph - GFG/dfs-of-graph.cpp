//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void traverse(std::vector<int> num[], int vertex, std::vector<int> &visited, std::vector<int> &result)
    {
        result.push_back(vertex);
        visited[vertex] = 1;
    
        for (auto i : num[vertex])
        {
            if (!visited[i])
                traverse(num, i, visited, result);
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> num[]) {
        // Code here
    std::vector<int> visited(v, 0);
    std::vector<int> result;

    traverse(num, 0, visited, result);
    return result;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends