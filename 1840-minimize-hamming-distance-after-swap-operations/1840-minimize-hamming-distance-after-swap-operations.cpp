class Solution {
public:

void traverse(std::vector<int> adj[], std::vector<int> &source, std::vector<int> &target, std::vector<int> &vis, std::map<int, int> &data1, std::map<int, int> &data2, int index)
{
    vis[index] = 1;
    for (auto i : adj[index])
    {
        if (vis[i] == 0)
            traverse(adj, source, target, vis, data1, data2, i);
    }

    data1[source[index]]++;
    data2[target[index]]++;
}

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& swap) {

    int n = source.size();
    std::vector<int> adj[n];
    for (int i = 0; i < swap.size(); i++)
    {
        adj[swap[i][0]].push_back(swap[i][1]);
        adj[swap[i][1]].push_back(swap[i][0]);
    }

    std::vector<int> vis(n, 0);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            std::map<int, int> data1, data2;
            traverse(adj, source, target, vis, data1, data2, i);

            int count = 0;
            for (auto j : data1)
                if (data1[j.first] > data2[j.first])
                     count += data1[j.first] - data2[j.first];

            res += count;
        }
    }

    return res;       
    }
};