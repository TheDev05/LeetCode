//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void traverse(std::vector<int> num[], std::vector<int> &vis, std::stack<int> &st, int index)
    {
        vis[index] = 1;
        for (auto i : num[index])
        {
            if (vis[i] == 0)
                traverse(num, vis, st, i);
        }
    
        st.push(index);
    }

	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> num[]) 
	{
	    // code here
    std::vector<int> vis(n, 0);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            traverse(num, vis, st, i);
    }

    std::vector<int> result;
    while (st.size())
    {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends