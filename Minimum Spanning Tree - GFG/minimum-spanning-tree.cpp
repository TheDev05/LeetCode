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

    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        
    dsu ds(n);
    std::vector<std::pair<int, std::pair<int, int>>> num;

    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            int adjNode = j[0];
            int adjWt = j[1];
            int node = i;
            
            num.push_back({adjWt, {node, adjNode}});
        }
    }

    std::sort(num.begin(), num.end());

    int sum = 0;
    for (auto i: num)
    {
        int adjWt = i.first;
        int node = i.second.first;
        int adjNode = i.second.second;

        if (ds.getParent(node) != ds.getParent(adjNode))
        {
            ds.getUnion(node, adjNode);
            sum += adjWt;
        }
    }

    return sum;
    
    // ***

    
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