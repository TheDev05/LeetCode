class Solution {
public:
    int change(int k, vector<int>& num) {
        
    std::vector<std::vector<int>> dp(num.size() + 1, std::vector<int>(k + 1, 0));
    dp[dp.size() - 1][0] = 1;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - num[i] >= 0)
                val1 = dp[i][j - num[i]];
            val2 = dp[i + 1][j];

            dp[i][j] = val1 + val2;
        }
    }

    return dp[0].back();
        
    }
};