class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& adj) {
        
    std::set<int> num[n];
    for (int i = 0; i < adj.size(); i++)
    {
        num[adj[i][0]].insert(adj[i][1]);
        num[adj[i][1]].insert(adj[i][0]);
        
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            int temp = (int)(num[i].size() + num[j].size());
            if (num[i].count(j))
                temp--;

            sum = std::max(sum, temp);
        }

        max = std::max(max, sum);
    }

    return max; 
        
    }
};