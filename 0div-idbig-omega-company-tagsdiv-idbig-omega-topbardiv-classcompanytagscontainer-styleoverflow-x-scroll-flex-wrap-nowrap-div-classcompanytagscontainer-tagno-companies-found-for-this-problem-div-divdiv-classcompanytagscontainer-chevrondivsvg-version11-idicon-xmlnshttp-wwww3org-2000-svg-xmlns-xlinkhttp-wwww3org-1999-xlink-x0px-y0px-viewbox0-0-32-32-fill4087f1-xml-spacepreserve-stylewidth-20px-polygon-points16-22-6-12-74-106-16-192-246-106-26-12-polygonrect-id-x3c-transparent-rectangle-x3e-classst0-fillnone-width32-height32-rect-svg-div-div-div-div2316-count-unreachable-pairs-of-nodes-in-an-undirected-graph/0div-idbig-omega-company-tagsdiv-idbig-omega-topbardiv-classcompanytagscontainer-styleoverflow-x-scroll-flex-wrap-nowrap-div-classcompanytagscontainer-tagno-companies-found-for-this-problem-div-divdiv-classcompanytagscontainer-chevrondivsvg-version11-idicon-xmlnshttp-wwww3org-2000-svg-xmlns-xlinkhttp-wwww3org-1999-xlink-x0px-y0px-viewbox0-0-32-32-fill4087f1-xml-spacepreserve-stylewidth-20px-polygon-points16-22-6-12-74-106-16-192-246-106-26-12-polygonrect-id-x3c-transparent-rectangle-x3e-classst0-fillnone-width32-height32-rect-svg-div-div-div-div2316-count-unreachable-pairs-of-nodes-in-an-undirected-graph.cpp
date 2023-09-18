class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& num) {
        
    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][0]].push_back(num[i][1]);
        adj[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> res, vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            std::queue<int> inox;

            inox.push(i);
            vis[i] = 1;

            int count = 0;
            while (inox.size())
            {
                auto it = inox.front();
                inox.pop();

                count++;
                int local = it;

                for (auto i : adj[local])
                {
                    if (vis[i] == 0)
                    {
                        vis[i] = 1;
                        inox.push(i);
                    }
                }
            }

            res.push_back(count);
        }
    }

    long long sum = accumulate(res.begin(), res.end(), (long long)0);
    long long total = 0;

    for (int i = 0; i < res.size(); i++)
    {
        total += (res[i] * (sum - res[i]));
        sum = sum - res[i];
    }

    return total;        
    }
};