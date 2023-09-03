class Solution {
public:
void traverse(std::vector<int> adj[], int index, int &resIndex, std::vector<int> &quiet, std::vector<int> &vis, int &val)
{
    vis[index] = 1;
    if(quiet[index] < val)
    {
        val = quiet[index];
        resIndex = index;
    }

    for (auto i : adj[index])
    {
        if (vis[i] == 0)
            traverse(adj, i, resIndex, quiet, vis, val);
    }
}

    vector<int> loudAndRich(vector<vector<int>>& num, vector<int>& quiet) {
    int n = quiet.size();
        
    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int val = INT_MAX, resIndex = i;
        std::vector<int> vis(n, 0);

        traverse(adj, i, resIndex, quiet, vis, val);
        res.push_back(resIndex);
    }  
    
    return res;
    }
};