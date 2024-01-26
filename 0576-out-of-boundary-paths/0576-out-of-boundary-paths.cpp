class Solution {
public:
int traverse(std::vector<std::vector<int>> &num, std::vector<std::vector<std::vector<int>>> &dp, int row, int col, int moves)
{
    int r[4] = {0, 0, 1, -1};
    int c[4] = {-1, 1, 0, 0};

    if (moves == 0)
        return 0;

    if (dp[row][col][moves] == -1)
    {
        int val = 0, count = 0, mod = 1e9 + 7;
        for (int i = 0; i < 4; i++)
        {
            int trow = row + r[i];
            int tcol = col + c[i];

            if (trow >= 0 && trow < num.size() && tcol >= 0 && tcol < num[0].size())
            {
                    val += (traverse(num, dp, trow, tcol, moves - 1) % mod);
                    val = val % mod;
            }
            else
                count++;
        }

        dp[row][col][moves] = count + val;
    }

    return dp[row][col][moves];
}
    
    int findPaths(int n, int m, int moves, int row, int col) {
        
    std::vector<std::vector<int>> num(n, std::vector<int>(m, 0));
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(moves + 1, -1)));

    return traverse(num, dp, row, col, moves);  
        
    }
};