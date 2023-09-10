class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& num, vector<int>& price, vector<int>& start, int k) {
        
    int n = num.size(), m = num[0].size();
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, greater<std::pair<int, std::pair<int, int>>>> inox;

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, 1e7));

    inox.push({0, {start[0], start[1]}});

    vis[start[0]][start[1]] = 1;
    dist[start[0]][start[1]] = 0;

    int left = price[0], right = price[1];

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    while (inox.size())
    {
        auto it = inox.top();
        inox.pop();

        int val = it.first;
        int row = it.second.first;
        int col = it.second.second;

        vis[row][col] = 1;

        for (int j = 0; j < 4; j++)
        {
            int trow = row + r[j];
            int tcol = col + c[j];

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] && vis[trow][tcol] == 0)
            {
                if (dist[row][col] + 1 < dist[trow][tcol])
                {
                    dist[trow][tcol] = dist[row][col] + 1;
                    inox.push({dist[trow][tcol], {trow, tcol}});
                }
            }
        }
    }

    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] >= left && num[i][j] <= right && vis[i][j])
                temp.insert({{dist[i][j], num[i][j]}, {i, j}});
        }
    }

    std::vector<std::vector<int>> res;
    while (k--)
    {
        if (temp.empty())
            break;

        auto it = temp.begin();

        std::vector<int> local(2);
        local[0] = it->second.first;
        local[1] = it->second.second;

        temp.erase(temp.begin());
        res.push_back(local);
    }
        
    return res;
    }
};