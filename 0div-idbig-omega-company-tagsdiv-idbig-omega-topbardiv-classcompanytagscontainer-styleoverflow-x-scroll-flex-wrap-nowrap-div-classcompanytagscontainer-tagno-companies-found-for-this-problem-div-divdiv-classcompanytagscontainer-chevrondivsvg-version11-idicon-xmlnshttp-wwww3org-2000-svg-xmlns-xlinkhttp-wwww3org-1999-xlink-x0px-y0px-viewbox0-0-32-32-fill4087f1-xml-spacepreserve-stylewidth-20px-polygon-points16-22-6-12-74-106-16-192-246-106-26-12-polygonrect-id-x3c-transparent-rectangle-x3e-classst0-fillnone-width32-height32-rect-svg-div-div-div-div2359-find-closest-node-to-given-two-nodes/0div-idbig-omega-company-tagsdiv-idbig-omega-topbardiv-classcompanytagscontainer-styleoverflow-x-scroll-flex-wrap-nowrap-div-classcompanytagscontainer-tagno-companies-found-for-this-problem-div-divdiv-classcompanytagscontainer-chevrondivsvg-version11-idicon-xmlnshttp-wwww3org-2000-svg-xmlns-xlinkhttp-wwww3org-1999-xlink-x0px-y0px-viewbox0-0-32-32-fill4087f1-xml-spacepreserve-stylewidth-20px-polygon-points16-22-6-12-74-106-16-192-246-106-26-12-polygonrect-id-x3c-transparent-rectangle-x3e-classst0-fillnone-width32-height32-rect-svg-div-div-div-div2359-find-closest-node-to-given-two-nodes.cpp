class Solution {
public:
std::pair<int, int> traverse(std::vector<int> adj[], int n, int n1, int n2)
{
    std::vector<int> vis(n, -1);
    std::queue<std::pair<int, int>> inox;

    inox.push({n1, 0});
    vis[n1] = 0;

    while (inox.size())
    {
        int it = inox.front().first;
        int dist = inox.front().second;
        inox.pop();

        for (auto i : adj[it])
        {
            if (vis[i] == -1)
            {
                vis[i] = dist + 1;
                inox.push({i, dist + 1});
            }
        }
    }

    std::vector<int> temp(n, -1);

    inox.push({n2, 0});
    temp[n2] = 0;

    while (inox.size())
    {
        int it = inox.front().first;
        int dist = inox.front().second;
        inox.pop();

        if (vis[it] != -1)
            return {it, vis[it]};

        for (auto i : adj[it])
        {
            if (temp[i] == -1)
            {
                temp[i] = dist + 1;
                inox.push({i, dist + 1});
            }
        }
    }

    return {-1, 1e6};
}

    int closestMeetingNode(vector<int>& num, int n1, int n2) {
    int n = num.size();

    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= 0)
            adj[i].push_back(num[i]);
    }

    auto it1 = traverse(adj, n, n1, n2);
    int node1 = it1.first;
    int dist1 = it1.second;

    auto it2 = traverse(adj, n, n2, n1);
    int node2 = it2.first;
    int dist2 = it2.second;

    int res = 0;
    if (dist1 < dist2)
        res = node1;
    else if (dist1 > dist2)
        res = node2;
    else
        res = std::min(node1, node2);

    return res;      
    }
};