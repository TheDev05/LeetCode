class Solution {
public:
    void traverse(std::vector<std::vector<char>> &num, std::vector<std::vector<int>> &vis, int i, int j)
    {
        std::queue<std::pair<int, int>> inox;

        int r[4] = {0, 0, -1, 1};
        int c[4] = {-1, 1, 0, 0};

        int n = num.size();
        int m = num[0].size();

        inox.push({i, j});
        while (inox.size())
        {
            int row = inox.front().first;
            int col = inox.front().second;

            vis[row][col] = 1;
            inox.pop();

            for (int k = 0; k < 4; k++)
            {
                int trow = row + r[k];
                int tcol = col + c[k];

                if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] == 'O' && vis[trow][tcol] == 0)
                    inox.push({trow, tcol}), vis[trow][tcol] = 1;
            }
        }
    }
    
    void solve(vector<vector<char>>& num) {
        
    int n = num.size(), m = num[0].size();
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        if (vis[i][0] == 0 && num[i][0] == 'O')
            traverse(num, vis, i, 0);
        if (vis[i][m - 1] == 0 && num[i][m - 1] == 'O')
            traverse(num, vis, i, m - 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (vis[0][i] == 0 && num[0][i] == 'O')
            traverse(num, vis, 0, i);
        if (vis[n - 1][i] == 0 && num[n - 1][i] == 'O')
            traverse(num, vis, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0)
                num[i][j] = 'X';
        }
    }    
        
    }
};