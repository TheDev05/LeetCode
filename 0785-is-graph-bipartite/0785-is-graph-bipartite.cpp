class Solution {
public:
    
    bool traverse(std::vector<int> adj[], std::vector<int> &vis, int index, bool color)
    {
        vis[index] = color;
        for (auto i : adj[index])
            if (vis[i] == -1)
            {
                if (traverse(adj, vis, i, !color))
                    return true;
            }
            else if (vis[i] == color)
                return true;

        return false;
    }
    
    bool isBipartite(vector<vector<int>>& num) {

    std::vector<int> adj[num.size()];
    for (int i = 0; i < num.size(); i++)
    {
        for (auto j : num[i])
            adj[i].push_back(j);
    }

    std::vector<int> vis(num.size(), -1);
    for(int i = 0; i < num.size(); i++)
        if(vis[i] == -1)
            if(traverse(adj, vis, i, 0))
                return false;

    return true;   
    }
};