class Solution {
public:
    int minReorder(int n, vector<vector<int>>& adj) {
        
    std::set<int> edges[n];
    std::vector<int> num[n];

    for (int i = 0; i < adj.size(); i++)
    {
        edges[adj[i][0]].insert(adj[i][1]);
        
        num[adj[i][0]].push_back(adj[i][1]);
        num[adj[i][1]].push_back(adj[i][0]);
    }

    std::queue<int> inox;
    std::vector<int> vis(n, 0);

    inox.push(0);
    vis[0] = 1;

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        for (auto i : num[local])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                inox.push(i);

                if (edges[i].count(local) == false)
                    count++;
            }
        }
    }

    return count;        
    }
};