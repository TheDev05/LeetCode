class Solution {
public:
    int traverse(std::string text, std::vector<int>&dp, int index)
    {
        if(text[index] == '0') return 0;
        if(index >= text.size()) return 1;
        
        if(dp[index] == -1)
        {
            int sum = 0, temp = 0;
            for(int i = index; i < text.size(); i++)
            {
                int val = (int)(text[i] - '0');
                temp = (temp * 10) + val;
                            
                if(temp < 27) sum += traverse(text, dp, i + 1);
                else break;
            }
            
            dp[index] = sum;
        }

        return dp[index];
    }
    
    int numDecodings(string s) {
       std::vector<int>dp(s.size() + 1, -1);
       return traverse(s, dp, 0);
    }
};