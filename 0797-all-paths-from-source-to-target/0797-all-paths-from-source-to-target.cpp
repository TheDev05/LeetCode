class Solution {
public:
void traverse(std::vector<int> adj[], std::vector<int> &temp, std::vector<std::vector<int>> &res, int n, int index)
{
    if (index == n)
    {
        res.push_back(temp);
        return;
    }

    for (auto i : adj[index])
    {
            temp.push_back(i);
            traverse(adj, temp, res, n, i);
            temp.pop_back();    
    }

    return;
}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& num) {
        
    std::vector<int> adj[num.size()];
    for (int i = 0; i < num.size(); i++)
    {
        for (auto j : num[i])
            adj[i].push_back(j);
    }

    std::vector<std::vector<int>> res;
    std::vector<int> temp(1, 0);

    traverse(adj, temp, res, num.size()-1, 0);  
    return res;
        
    }
};