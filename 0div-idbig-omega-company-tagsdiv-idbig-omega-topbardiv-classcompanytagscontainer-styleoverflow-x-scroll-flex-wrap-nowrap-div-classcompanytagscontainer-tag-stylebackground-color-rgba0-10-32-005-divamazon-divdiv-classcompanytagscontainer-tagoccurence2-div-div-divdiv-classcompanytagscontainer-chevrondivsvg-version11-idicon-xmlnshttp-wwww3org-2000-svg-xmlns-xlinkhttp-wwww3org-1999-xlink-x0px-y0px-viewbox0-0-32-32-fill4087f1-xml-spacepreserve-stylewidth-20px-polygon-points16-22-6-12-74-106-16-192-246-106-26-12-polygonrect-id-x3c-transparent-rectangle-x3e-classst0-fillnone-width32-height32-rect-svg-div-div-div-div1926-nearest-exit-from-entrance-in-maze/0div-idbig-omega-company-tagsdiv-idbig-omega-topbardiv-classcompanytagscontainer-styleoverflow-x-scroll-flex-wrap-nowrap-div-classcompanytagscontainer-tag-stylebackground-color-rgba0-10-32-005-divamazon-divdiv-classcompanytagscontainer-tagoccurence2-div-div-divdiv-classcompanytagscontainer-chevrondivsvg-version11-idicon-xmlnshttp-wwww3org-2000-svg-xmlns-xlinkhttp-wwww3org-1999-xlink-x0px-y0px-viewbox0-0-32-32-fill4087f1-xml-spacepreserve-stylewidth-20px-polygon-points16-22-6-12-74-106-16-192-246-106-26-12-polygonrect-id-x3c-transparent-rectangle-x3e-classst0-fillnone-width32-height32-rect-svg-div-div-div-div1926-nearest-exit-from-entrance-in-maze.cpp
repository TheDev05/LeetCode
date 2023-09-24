class Solution {
public:
    int nearestExit(vector<vector<char>>& num, vector<int>& start) {
    int n = num.size(), m = num[0].size();
        
    std::queue<std::pair<std::pair<int, int>, int>> inox;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == start[0] && j == start[1]){}
            else if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && num[i][j] == '.')
            {
                inox.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int res = -1;
    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        int row = it.first.first;
        int col = it.first.second;

        int dist = it.second;

        if (row == start[0] && col == start[1])
        {
            res = dist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int trow = row + dx[i];
            int tcol = col + dy[i];

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] == '.' && vis[trow][tcol] == 0)
            {
                vis[trow][tcol] = 1;
                inox.push({{trow, tcol}, dist + 1});
            }
        }
    }

    return res;        
    }
};