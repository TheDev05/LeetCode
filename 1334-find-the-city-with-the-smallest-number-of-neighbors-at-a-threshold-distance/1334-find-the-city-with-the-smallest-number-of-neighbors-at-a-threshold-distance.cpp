class Solution {
public:
int dijkstra(int src, int target, int n, std::vector<std::pair<int, int>> num[])
{
    std::vector<int> dist(n, 1e7);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<std::pair<int, int>>> inox;

    inox.push({0, src});
    dist[src] = 0;

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int node = it.second;
        int wt = it.first;

        for (auto i : num[node])
        {
            int adjNode = i.first;
            int adjWt = i.second;

            if (wt + adjWt < dist[adjNode])
            {
                dist[adjNode] = wt + adjWt;
                inox.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist[target];
}
    
    int findTheCity(int n, vector<vector<int>>& adj, int lim) {
        
    std::vector<std::pair<int, int>> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        num[adj[i][1]].push_back({adj[i][0], adj[i][2]});
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = dijkstra(i, j, n, num);
        }
    }
        
    std::vector<int> inox(n, 0);

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] && dist[i][j] <= lim)
                count++;
        }

        inox[i] = count;
        min = std::min(min, count);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (inox[i] == min)
            max = std::max(max, i);
    }

    return max;
        
    }
};