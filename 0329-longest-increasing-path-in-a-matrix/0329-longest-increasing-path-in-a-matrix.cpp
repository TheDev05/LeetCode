class Solution {
public:
    
static bool cmp(std::pair<int, std::pair<int, int>> a, std::pair<int, std::pair<int, int>> b)
{
    return a.first < b.first;
}
    
    int longestIncreasingPath(vector<vector<int>>& num) {
        
    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    std::vector<std::pair<int, std::pair<int, int>>> data;
    std::vector<std::vector<int>> vis(num.size(), std::vector<int>(num[0].size(), 1));

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            data.push_back({num[i][j], {i, j}});
        }
    }

    sort(begin(data), end(data), cmp);

    std::queue<std::pair<int, int>> inox;
    for (auto i : data)
        inox.push({i.second.first, i.second.second});

    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        int row = it.first;
        int col = it.second;

        for (int k = 0; k < 4; k++)
        {
            int trow = row + r[k];
            int tcol = col + c[k];

            if (trow >= 0 && trow < num.size() && tcol >= 0 && tcol < num[0].size() && num[trow][tcol] > num[row][col])
            {
                if (vis[trow][tcol] == 1)
                    inox.push({trow, tcol});

                vis[trow][tcol] = std::max(vis[trow][tcol], 1 + vis[row][col]);
            }
        }
    }

    int max = 0;
    for (auto i : vis)
    {
        for (auto j : i)
            max = std::max(max, j);
    }

    return max;    
        
    }
};