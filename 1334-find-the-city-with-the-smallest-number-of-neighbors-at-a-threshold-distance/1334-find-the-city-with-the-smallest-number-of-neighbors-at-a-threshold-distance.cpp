class Solution {
public:
    void traverse(std::vector<std::pair<int, int>> adj[], std::map<int, int> &data, int index, int limit, int n)
    {
        // dist, node
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<std::pair<int, int>>> inox;
        std::vector<int> distance(n, INT_MAX);

        inox.push({0, index});
        distance[index] = 0;

        while (inox.size())
        {
            auto [dist, node] = inox.top();
            inox.pop();

            for (auto [adjNode, adjDist] : adj[node])
            {
                if (dist + adjDist < distance[adjNode])
                {
                    distance[adjNode] = dist + adjDist;
                    inox.push({distance[adjNode], adjNode});
                }
            }
        }

        for (int i = 0; i < distance.size(); i++)
        {
            if (distance[i] > limit)
                continue;

            data[i]++;
        }
    }

    int findTheCity(int n, vector<vector<int>>& num, int limit) {
        
    // node, weight
    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][0]].push_back({num[i][1], num[i][2]});
        adj[num[i][1]].push_back({num[i][0], num[i][2]});
    }

    std::map<int, int> data;
    for (int i = 0; i < n; i++)
    {
        traverse(adj, data, i, limit, n);
    }

    int min = INT_MAX, ans = 0;
    for (auto i : data)
        if (i.second <= min)
            min = i.second, ans = std::max(ans, i.first);

    return ans;
        
    }
};