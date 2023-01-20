class Solution {
public:
    int coinChange(vector<int>& num, int k) {
        
    std::vector<int> prev(k + 1, 1e8), curr(k + 1, 1e8);
    prev[0] = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < k + 1; j++)
        {
            int val1 = 1e8, val2 = 1e8;
            if (j - num[i] >= 0)
                val1 = 1 + curr[j - num[i]];
            val2 = prev[j];

            curr[j] = std::min(val1, val2);
        }

        prev = curr;
    }

    int res = curr[k];
    if(res == 1e8) res = -1;
        
    return res;
        
    }
};