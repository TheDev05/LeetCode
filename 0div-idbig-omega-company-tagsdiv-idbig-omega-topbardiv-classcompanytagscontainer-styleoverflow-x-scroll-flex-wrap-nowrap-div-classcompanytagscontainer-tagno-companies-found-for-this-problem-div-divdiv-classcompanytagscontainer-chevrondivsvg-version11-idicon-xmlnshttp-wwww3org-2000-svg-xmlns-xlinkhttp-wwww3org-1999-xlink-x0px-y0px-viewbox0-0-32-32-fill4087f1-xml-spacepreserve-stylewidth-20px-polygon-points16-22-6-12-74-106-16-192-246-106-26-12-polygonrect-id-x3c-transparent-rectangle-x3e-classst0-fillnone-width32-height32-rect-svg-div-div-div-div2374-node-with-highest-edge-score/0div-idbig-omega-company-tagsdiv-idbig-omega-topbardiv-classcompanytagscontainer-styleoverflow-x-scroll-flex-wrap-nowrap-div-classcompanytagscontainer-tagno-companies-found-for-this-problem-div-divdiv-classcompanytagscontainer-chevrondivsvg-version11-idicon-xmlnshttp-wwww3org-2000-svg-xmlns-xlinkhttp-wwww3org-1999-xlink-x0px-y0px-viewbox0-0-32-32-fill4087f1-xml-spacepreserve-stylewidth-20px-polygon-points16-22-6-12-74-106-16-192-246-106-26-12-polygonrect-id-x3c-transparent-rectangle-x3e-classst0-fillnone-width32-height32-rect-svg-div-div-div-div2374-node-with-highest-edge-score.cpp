class Solution {
public:
    int edgeScore(vector<int>& num) {
    int n = num.size();
        
    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(num[i]);
    }

    std::vector<long long> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
            res[j] += i;
    }

    long long max = 0, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (res[i] > max)
            max = res[i], index = i;
    }

    return index;  
        
    }
};