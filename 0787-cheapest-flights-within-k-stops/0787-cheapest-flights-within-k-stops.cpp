class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& adj, int src, int dst, int k) {
    
    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
    }

    std::queue<std::pair<int, std::pair<int, int>>> inox;

    std::vector<int> stops(n, 1e7);
    std::vector<int> dist(n, 1e7);

    inox.push({src, {0, 0}});
    dist[src] = 0;

    while (inox.size())
    {
        int node = inox.front().first;
        int len = inox.front().second.first;
        int val = inox.front().second.second;

        inox.pop();

        if(len > k) continue;
        for (auto i : num[node])
        {
            int adjNode = i.first;
            int adjLen = i.second;

            if (val + adjLen < dist[adjNode] )
            {
                dist[adjNode] = val + adjLen;
                stops[adjNode] = len + 1;

                inox.push({adjNode, {stops[adjNode], dist[adjNode]}});
            }
        }
    }
    
    if(dist[dst] == 1e7) return -1;
    
    return dist[dst];
    }
};