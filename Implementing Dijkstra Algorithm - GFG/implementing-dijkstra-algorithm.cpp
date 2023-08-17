//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> num[], int src)
    {
        // Code here
    std::vector<int> dist(v, 1e5 + 1);
    std::set<std::pair<int, int>> inox;

    inox.insert({0, src});
    dist[src] = 0;

    while (inox.size())
    {
        int node = inox.begin()->second;
        int wt = inox.begin()->first;

        inox.erase(inox.begin());

        for (auto it : num[node])
        {
            int adj_node = it[0];
            int adj_wt = it[1];

            if (dist[node] + adj_wt < dist[adj_node])
            {
                if (inox.count({dist[adj_node], adj_node}))
                    inox.erase({dist[adj_node], adj_node});

                dist[adj_node] = dist[node] + adj_wt;
                inox.insert({dist[adj_node], adj_node});
            }
        }
    }

    return dist;
    
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends