class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& adj) {
        
    std::vector<int> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back(adj[i][1]);
        num[adj[i][1]].push_back(adj[i][0]);
    }

    std::vector<int> vis(n, 0);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            std::queue<int> inox;

            inox.push(i);
            vis[i] = 1;

            int edges = INT_MAX, size = 0;
            while (inox.size())
            {
                int local = inox.front();
                inox.pop();

                size++;
                edges = std::min((int)(num[local].size()), edges);

                for (auto j : num[local])
                {
                    if (vis[j] == 0)
                    {
                        vis[j] = 1;
                        inox.push(j);
                    }
                }
            }

            if (edges >= size - 1)
                res++;
        }
    }

    return res;  
        
    }
};