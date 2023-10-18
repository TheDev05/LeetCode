class Solution {
public:
std::map<char, int> traverse(std::vector<int> adj[], std::vector<int> &vis, std::string &text, std::vector<int> &res, int index)
{
    vis[index] = 1;
    std::map<char, int> data;

    for (auto i : adj[index])
    {
        if (vis[i] == 0)
        {
            std::map<char, int> temp;
            temp = traverse(adj, vis, text, res, i);

            for (auto j : temp)
                data[j.first] += j.second;
        }
    }

    data[text[index]]++;
    res[index] = data[text[index]];
    
    return data;
}
    
    vector<int> countSubTrees(int n, vector<vector<int>>& num, string text) {
        
    std::vector<int> adj[n];
    for (int i = 0; i < num.size(); i++)
    {
        adj[num[i][1]].push_back(num[i][0]);
        adj[num[i][0]].push_back(num[i][1]);
    }

    std::vector<int> vis(n, 0), res(n, 0);
    traverse(adj, vis, text, res, 0);
        
    return res;
    }
};