class Solution {
public:
    int findLength(vector<int>& num1, vector<int>& num2) {
        
    std::vector<std::vector<int>> dp(num1.size() + 1, std::vector<int>(num2.size() + 1, 0));
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            int val = 0;
            if (num1[i] == num2[j])
                val = 1 + dp[i + 1][j + 1];

            dp[i][j] = val;
        }
    }

    int max = 0;
    for (auto i : dp)
        for (auto j : i)
            max = std::max(max, j);

    return max;  
        
    }
};