class Solution {
public:
    void solve(vector<vector<char>>& num) {
        
    std::queue<std::pair<int, int>> inox;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            if ((i == 0 || i == num.size() - 1 || j == 0 || j == num[0].size() - 1) && (num[i][j] == 'O'))
                inox.push({i, j});
        }
    }

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    while (inox.size())
    {
        auto [row, col] = inox.front();
        inox.pop();

        num[row][col] = '.';

        for (int i = 0; i < 4; i++)
        {
            int trow = row + r[i];
            int tcol = col + c[i];

            if (trow >= 0 && trow < num.size() && tcol >= 0 && tcol < num[0].size() && num[trow][tcol] == 'O')
                inox.push({trow, tcol});
        }
    }

    for (auto &i : num)
        for (auto &j : i)
            if (j == '.')
                j = 'O';
            else
                j = 'X'; 
        
    }
};