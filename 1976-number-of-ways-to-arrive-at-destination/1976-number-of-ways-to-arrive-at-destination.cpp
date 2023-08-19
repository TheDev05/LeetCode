class Solution {
public:
    int countPaths(int n, vector<vector<int>>& adj) {
        
    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        num[adj[i][1]].push_back({adj[i][0], adj[i][2]});
    }

    std::vector<long long> dist(n, LONG_MAX);
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, greater<std::pair<long long, long long>>> inox;

    inox.push({0, 0});
    dist[0] = 0;

    // dist, node

    int mod = 1e9 + 7;
        
    std::map<std::pair<long long, long long>, long long> data;
    data[{0, 0}] = 1;

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        long long node = it.second;
        long long wt = it.first;

        for (auto i : num[node])
        {
            long long adjNode = i.first;
            long long adjWt = i.second;

            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                inox.push({dist[adjNode], adjNode});
            }
            
            data[{(wt + adjWt), adjNode}] += (data[{wt, node}]) % mod;
        }
    }

    return data[{dist[n - 1], n - 1}] % mod;       
    }
};