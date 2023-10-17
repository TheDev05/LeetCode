class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        if (left[i] >= 0)
            adj[i].push_back(left[i]);
        if (right[i] >= 0)
            adj[i].push_back(right[i]);
    }

    std::vector<int> indeg(n, 0), outdeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indeg[adj[i][j]]++;
        }

        outdeg[i] = adj[i].size();
    }

    std::queue<int> inox;
    std::vector<int> vis(n, 0);

    vis[0] = 1;
    inox.push(0);

    bool ok = false;
    while (inox.size())
    {
        int it = inox.front();
        inox.pop();

        int count = 0;
        for (auto i : adj[it])
        {
            if (vis[i])
                count++;
            else
            {
                vis[i] = 1;
                inox.push(i);
            }
        }

        if (count)
        {
            ok |= true;
            return false;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] > 1 || outdeg[i] > 2)
            return false;
        if (indeg[i] == 0)
            count++;
    }

    if (count > 1)
        return false;

    return true;        
    }
};