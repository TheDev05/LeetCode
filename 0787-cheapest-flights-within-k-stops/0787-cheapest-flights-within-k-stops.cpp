class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& adj, int src, int target, int min_stops) {
        
    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
    }
        
    std::vector<int> dist(n, INT_MAX);
    std::priority_queue<std::pair<std::pair<int, int>, int>, std::vector<std::pair<std::pair<int, int>, int>>, greater<std::pair<std::pair<int, int>, int>>> pq;

    dist[src] = 0;
    pq.push({{0, 0}, src});

    // stops, dist, node

    while (pq.size())
    {
        auto it = pq.top();
        pq.pop();

        int stops = it.first.first;
        int wt = it.first.second;
        int node = it.second;

        if (stops > min_stops)
            continue;

        for (auto i : num[node])
        {
            int adjNode = i.first;
            int adjWt = i.second;

            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                pq.push({{stops + 1, dist[adjNode]}, adjNode});
            }
        }
    }
        
    if(dist[target] == INT_MAX) return -1;
    return dist[target];         
    }
};