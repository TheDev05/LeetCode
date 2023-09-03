class Solution {
public:

bool traverse(std::vector<int> adj[], std::vector<int> &vis, int n, int u, int v)
{
    vis[u] = 1;
    for (auto i : adj[u])
    {
        if (i == v)
            return true;

        if (vis[i] == 0)
            if (traverse(adj, vis, n, i, v))
                return true;
    }

    return false;
}

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& num, vector<vector<int>>& queries) {
        
    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][0]].push_back(num[i][1]);
    }

    std::vector<bool> res;
    for (int i = 0; i < queries.size(); i++)
    {
        std::vector<int> vis(n, 0);
        res.push_back(traverse(adj, vis, n, queries[i][0], queries[i][1]));
    }

    return res;       
    }
};