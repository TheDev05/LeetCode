class Solution {
public:
void getPack(int j, std::set<int> &temp, std::vector<int> local[], std::set<int> &vis)
{
    temp.insert(j);
    vis.insert(j);

    for (auto i : local[j])
        if (vis.count(i) == false)
            getPack(i, temp, local, vis);
}

vector<vector<int>> getAncestors(int n, vector<vector<int>>& adj) {
    int m = adj.size();
    
    std::vector<int> num[n];
    std::vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++)
    {
        num[adj[i][0]].push_back(adj[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        for (auto j : num[i])
            indeg[j]++;
    }

    std::queue<int> inox;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            inox.push(i);
    }

    std::vector<int> topo;
    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        topo.push_back(it);

        for (auto i : num[it])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                inox.push(i);
        }
    }

    std::vector<int> local[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            local[num[i][j]].push_back(i);
        }
    }

    std::vector<std::vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        std::set<int> temp;
        std::set<int> vis;

        for (auto j : local[i])
            getPack(j, temp, local, vis);

        std::vector<int> atom;
        for (auto k : temp)
            atom.push_back(k);
            
        res.push_back(atom);
    }
    
    return res;
    
    }
};