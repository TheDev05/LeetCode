class Solution {
public:
    int traverse(std::vector<int> adj[], std::vector<int> &vis, int index)
    {
        vis[index] = 1;
        int count = 0;

        for (auto i : adj[index])
        {
            if (vis[i] == -1)
                count += traverse(adj, vis, i);
            else
                count += vis[i];
        }

        count = count ? 1 : 0;
        vis[index] = count;

        return count;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& num) {
    int n = num.size();
        
    std::vector<int> adj[num.size()];
    for (int i = 0; i < num.size(); i++)
    {
        adj[i] = num[i];
    }

    std::vector<int> vis(num.size(), -1);

    for (int i = 0; i < num.size(); i++)
    {
        if (vis[i] == -1)
            traverse(adj, vis, i);
    }

    std::vector<int> res;
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            res.push_back(i); 
        
    return res;
    }
};