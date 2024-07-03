class Solution {
public:

int traverse(std::vector<int> adj[], std::vector<int> &vis, int index, std::vector<int> &temp, std::set<int> &res, int &max)
{
    vis[index] = 1;
    for (auto i : adj[index])
    {
        if (vis[i] == 0)
        {
            temp.push_back(i);
            traverse(adj, vis, i, temp, res, max);
            temp.pop_back();
        }
    }

    if (temp.size() > max)
    {
        max = temp.size();
        res.clear();

        if (temp.size() & 1)
            res.insert(temp[temp.size() / 2]);
        else
        {
            res.insert(temp[(temp.size() / 2) - 1]);
            res.insert(temp[temp.size() / 2]);
        }
    }

    return 0;
}

int bfs(std::vector<int> adj[], int n)
{
    std::queue<int> inox;
    std::vector<int> dist(n, 0), vis(n, 0);

    inox.push(0);
    vis[0] = 1;

    while (inox.size())
    {
        int local = inox.front();
        inox.pop();

        for (auto i : adj[local])
        {
            if (vis[i] == 0)
            {
                dist[i] = dist[local] + 1;
                
                inox.push(i);
                vis[i] = 1;
            }
        }
    }

    int max = 0, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < dist[i])
        {
            max = dist[i];
            index = i;
        }
    }

    return index;
}
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& num) {

    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][0]].push_back(num[i][1]);
        adj[num[i][1]].push_back(num[i][0]);
    }

    std::vector<int> temp, vis(n, 0);
    std::set<int> res;

    int max = 0, min = INT_MAX;
    int index = bfs(adj, n);

    temp.push_back(index);
    traverse(adj, vis, index, temp, res, max);

    std::vector<int> result;
    for (auto i : res)
        result.push_back(i);
      
    return result;
    }
};