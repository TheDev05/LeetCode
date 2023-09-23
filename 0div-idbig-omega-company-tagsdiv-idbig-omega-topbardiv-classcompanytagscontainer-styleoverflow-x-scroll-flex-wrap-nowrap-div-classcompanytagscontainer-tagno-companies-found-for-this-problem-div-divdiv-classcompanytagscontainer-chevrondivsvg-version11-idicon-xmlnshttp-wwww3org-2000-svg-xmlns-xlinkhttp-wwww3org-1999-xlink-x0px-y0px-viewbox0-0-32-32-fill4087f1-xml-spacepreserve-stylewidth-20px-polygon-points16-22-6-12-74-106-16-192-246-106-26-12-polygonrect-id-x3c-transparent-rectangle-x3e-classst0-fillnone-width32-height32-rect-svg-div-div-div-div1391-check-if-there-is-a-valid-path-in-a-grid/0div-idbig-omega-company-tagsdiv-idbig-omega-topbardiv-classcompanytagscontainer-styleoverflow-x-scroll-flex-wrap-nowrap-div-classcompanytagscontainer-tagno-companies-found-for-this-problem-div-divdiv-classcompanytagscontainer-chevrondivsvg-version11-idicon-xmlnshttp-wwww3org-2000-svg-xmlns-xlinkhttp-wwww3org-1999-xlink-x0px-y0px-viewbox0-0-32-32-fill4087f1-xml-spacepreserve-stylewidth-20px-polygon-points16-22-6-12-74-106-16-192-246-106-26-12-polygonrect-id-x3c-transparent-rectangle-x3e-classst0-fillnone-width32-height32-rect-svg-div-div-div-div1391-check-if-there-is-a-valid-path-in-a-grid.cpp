class Solution {
public:
    bool hasValidPath(vector<vector<int>>& num) {
        
    int n = num.size(), m = num[0].size();
    std::map<int, std::set<std::pair<int, int>>> data;

    data[1].insert({0, 1});
    data[1].insert({0, -1});

    data[2].insert({1, 0});
    data[2].insert({-1, 0});

    data[3].insert({0, -1});
    data[3].insert({1, 0});

    data[4].insert({1, 0});
    data[4].insert({0, 1});

    data[5].insert({0, -1});
    data[5].insert({-1, 0});

    data[6].insert({0, 1});
    data[6].insert({-1, 0});

    std::queue<std::pair<int, int>> inox;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    inox.push({0, 0});
    vis[0][0] = 1;

    bool ok = false;
    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        int row = it.first;
        int col = it.second;

        if (row == n - 1 && col == m - 1)
        {
            ok = true;
            break;
        }

        for (auto i : data[num[row][col]])
        {
            int trow = row + i.first;
            int tcol = col + i.second;

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && vis[trow][tcol] == 0)
            {
                for (auto j : data[num[trow][tcol]])
                    if (j.first + trow == row && j.second + tcol == col)
                    {
                        vis[trow][tcol] = 1;
                        inox.push({trow, tcol});
                    }
            }
        }
    }

    return ok;        
    }
};