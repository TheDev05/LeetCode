class Solution {
public:
    int climbStairs(int n) {
        
    std::vector<int> dp(n + 1, 0);
    dp[dp.size() - 1] = 1;

    for (int i = dp.size() - 2; i >= 0; i--)
    {
        int next = 0, nextNext = 0;
        if (i + 1 < dp.size())
            next = dp[i + 1];
        if (i + 2 < dp.size())
            nextNext = dp[i + 2];

        dp[i] = next + nextNext;
    }

    return dp[0]; 
        
    }
};