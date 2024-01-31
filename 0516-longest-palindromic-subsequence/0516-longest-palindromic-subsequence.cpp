class Solution {
public:
    int longestPalindromeSubseq(string text) {
        
    std::string temp = text;
    reverse(temp.begin(), temp.end());

    std::vector<std::vector<int>> dp(text.size() + 1, std::vector<int>(temp.size() + 1, 0));
    for (int i = text.size() - 1; i >= 0; i--)
    {
        for (int j = temp.size() - 1; j >= 0; j--)
        {
            int val = 0;
            if (text[i] == temp[j])
                val = 1 + dp[i + 1][j + 1];
            else
                val = std::max(dp[i][j + 1], dp[i + 1][j]);

            dp[i][j] = val;
        }
    }

    return dp[0][0]; 
        
    }
};
