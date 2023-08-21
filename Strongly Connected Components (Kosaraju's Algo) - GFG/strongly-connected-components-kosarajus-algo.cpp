//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
    void dfs(std::vector<std::vector<int>> &adj, std::vector<int> &vis, std::stack<int> &st, int index)
    {
        vis[index] = 1;
        for (auto i : adj[index])
        {
            if (vis[i] == 0)
                dfs(adj, vis, st, i);
        }
    
        st.push(index);
    }
    
    void dfs2(std::vector<int> num[], std::vector<int> &vis, int index)
    {
        vis[index] = 1;
        for (auto i : num[index])
        {
            if (vis[i] == 0)
                dfs2(num, vis, i);
        }
    }

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
    std::vector<int> vis(n, 0);
    std::stack<int> st;

    for (int i = 0; i < adj.size(); i++)
    {
        if (vis[i] == 0)
            dfs(adj, vis, st, i);
    }

    std::vector<int> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        for (auto it : adj[i])
        {
            num[it].push_back(i);
        }
    }


    std::set<int> inox;
    std::vector<int>visited(n, 0);
    
    int count = 0;
    while (st.size())
    {
        int val = st.top();
        st.pop();
        
        if (visited[val] == 0)
        {
            count++;
            dfs2(num, visited, val);
        }
    }

    return count;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends