//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
   
class dsu
{
    std::vector<int> parent, cmp_size;

public:
    dsu(int n)
    {
        cmp_size.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
            cmp_size[i] = 1;
        }
    }

    int getParent(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;

        return parent[vertex] = getParent(parent[vertex]);
    }

    void getUnion(int u, int v)
    {
        int parent_u = getParent(u);
        int parent_v = getParent(v);

        if (parent_u == parent_v)
            return;

        if (cmp_size[parent_u] > cmp_size[parent_v])
        {
            parent[parent_v] = parent_u;
            cmp_size[parent_u] += cmp_size[parent_v];
        }
        else
        {
            parent[parent_u] = parent_v;
            cmp_size[parent_v] += cmp_size[parent_u];
        }
    }
};

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        dsu ds(V);
        sort(edges.begin(), edges.end());
        
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.getParent(u) != ds.getParent(v)) {
                mstWt += wt;
                ds.getUnion(u, v);
            }
        }

        return mstWt;
    
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