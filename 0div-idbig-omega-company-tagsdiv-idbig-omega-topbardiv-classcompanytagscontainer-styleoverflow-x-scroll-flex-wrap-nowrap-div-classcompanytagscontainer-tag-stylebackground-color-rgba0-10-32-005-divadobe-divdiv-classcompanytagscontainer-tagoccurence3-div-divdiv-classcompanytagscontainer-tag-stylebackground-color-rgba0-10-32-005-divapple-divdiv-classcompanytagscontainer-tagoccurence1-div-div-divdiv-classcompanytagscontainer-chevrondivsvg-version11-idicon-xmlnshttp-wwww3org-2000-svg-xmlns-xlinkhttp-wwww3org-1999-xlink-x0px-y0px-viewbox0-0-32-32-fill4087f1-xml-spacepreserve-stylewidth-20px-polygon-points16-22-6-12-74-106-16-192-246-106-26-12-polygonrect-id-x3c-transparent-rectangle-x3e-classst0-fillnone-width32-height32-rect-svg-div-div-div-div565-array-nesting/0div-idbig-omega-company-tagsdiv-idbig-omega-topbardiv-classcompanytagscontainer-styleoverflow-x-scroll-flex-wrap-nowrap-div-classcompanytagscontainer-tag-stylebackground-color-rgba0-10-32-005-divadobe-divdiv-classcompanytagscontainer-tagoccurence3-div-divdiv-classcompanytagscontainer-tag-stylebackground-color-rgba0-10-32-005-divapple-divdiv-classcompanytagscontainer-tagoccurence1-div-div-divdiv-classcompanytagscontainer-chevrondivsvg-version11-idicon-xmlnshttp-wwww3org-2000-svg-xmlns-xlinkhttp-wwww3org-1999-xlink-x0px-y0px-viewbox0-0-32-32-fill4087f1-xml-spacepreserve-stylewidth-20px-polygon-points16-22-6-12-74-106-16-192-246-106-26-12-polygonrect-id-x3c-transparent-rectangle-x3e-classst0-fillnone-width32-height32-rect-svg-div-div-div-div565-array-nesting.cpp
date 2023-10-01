class Solution {
public:
int traverse(std::vector<int> &num, std::vector<int> &vis, int index, int count)
{
    if (vis[index] == -1)
    {
        vis[index] = 0;
        vis[index] = traverse(num, vis, num[index], count + 1);

        return vis[index];
    }
    else
        return count;
}

    int arrayNesting(vector<int>& num) {
        
    int n = num.size();
    std::vector<int> vis(n, -1);

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[num[i]] == -1)
            vis[num[i]] = traverse(num, vis, num[i], 0);

        max = std::max(max, vis[num[i]]);
    }

    return max;        
    }
};