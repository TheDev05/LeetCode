class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, std::vector<int> &vis, std::vector<int> &pathvis, int index)
{
    vis[index] = 1;
    pathvis[index] = 1;

    for (auto i : num[index])
    {
        if (vis[i] == 0)
        {
            if (traverse(num, vis, pathvis, i))
                return 1;
        }
        else if (pathvis[i])
            return 1;
    }

    pathvis[index] = 0;
    return 0;
}

    
    vector<int> eventualSafeNodes(vector<vector<int>>& num) {
    
    int n = num.size();
        
    std::vector<int> vis(n, 0), pathvis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            traverse(num, vis, pathvis, i);
        }
    }

    std::vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (pathvis[i] == 0)
            result.push_back(i);
    }

    return result;       
        
    }
};