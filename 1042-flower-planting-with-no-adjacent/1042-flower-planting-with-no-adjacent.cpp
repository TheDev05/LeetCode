class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& num) {
        
    std::vector<int> adj[n + 1];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][0]].push_back(num[i][1]);
        adj[num[i][1]].push_back(num[i][0]);
    }

    std::queue<int> inox;
    std::vector<int> vis(n + 1, 0), plants(n, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            inox.push(i);
            vis[i] = 1;

            while (inox.size())
            {
                int local = inox.front();
                inox.pop();

                std::vector<int> draft(5,0);
                for (auto i : adj[local])
                {
                    if (vis[i] == 0)
                    {
                        vis[local] = 1;
                        inox.push(i);
                    }

                    draft[plants[i-1]] = 1;
                }

                for (int j = 1; j <= 4; j++)
                {
                    if (draft[j] == 0)
                    {
                        plants[local - 1] = j;
                        break;
                    }
                }
            }
        }
    }

    for (auto i : plants)
        std::cout << i << " ";
        
    return plants;
    }
};