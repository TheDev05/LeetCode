class Solution {
public:
    bool traverse(std::vector<int> adj[], std::vector<int> &vis, int node)
    {
        vis[node] = -1;
        for (auto i : adj[node])
            if (vis[i] == 0)
            {
                if (traverse(adj, vis, i))
                    return true;
            }
            else if (vis[i] == -1)
                return true;

        vis[node] = 1;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& num) {

    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            if (traverse(adj, vis, i))
                return false;
    }

    return true;
        
    }
};