//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, greater<std::pair<int, std::pair<int, int>>>> inox;

    std::vector<int> vis(n, 0);
    std::vector<std::pair<int, int>> mst;

    // {wt, node, parent}
    
    inox.push({0, {0, -1}});
    int sum = 0;

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;
        mst.push_back({parent, node});  

        for (auto i : adj[node])
        {
            int adjNode = i[0];
            int adjWt = i[1];

            if (vis[adjNode] == 0)
                inox.push({adjWt, {adjNode, node}});
        }
    }

    return sum;
    
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends