class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& adj, vector<int>& restricted) {
    std::set<int> avoid;
    for (auto i : restricted)
        avoid.insert(i);

    std::vector<int> num[n];
    for (int i = 0; i < n - 1; i++)
    {
        num[adj[i][0]].push_back(adj[i][1]);
        num[adj[i][1]].push_back(adj[i][0]);
    }

    std::queue<int> inox;
    std::vector<int> vis(n, 0);

    inox.push(0);
    vis[0] = 1;

    int count = 0;
    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        count++;
        for (auto i : num[local])
        {
            if (vis[i] == 0 && avoid.count(i) == false)
            {
                vis[i] = 1;
                inox.push(i);
            }
        }
    }

    return count;        
    }
};