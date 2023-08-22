class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int src, int target) {
        
    std::vector<std::pair<int, double>> num[n];
    for (int i = 0; i < edges.size(); i++)
    {
        num[edges[i][0]].push_back({edges[i][1], prob[i]});
        num[edges[i][1]].push_back({edges[i][0], prob[i]});
        
    }

    std::vector<double> dist(n, 0);
    std::priority_queue<std::pair<double, int>>pq;

    pq.push({1.0, src});
    dist[src] = 1.0;

    while (pq.size())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        for (auto i : num[node])
        {
            int adjNode = i.first;
            double adjWt = i.second;

            if (dist[node] * adjWt > dist[adjNode])
            {
                dist[adjNode] = dist[node] * adjWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
                
    return dist[target];        
    }
};