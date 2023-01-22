class Solution {
public:
    int numSquares(int n) {
        
    std::vector<int> num;
    for (int i = 1; i <= n; i++)
    {
        double temp = sqrt(i);
        if (ceil(temp) == floor(temp))
            num.push_back(i);
    }

    std::vector<int> prev(n + 1, 1e7);
    prev[0] = 0;
    
    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size(); j++)
        {
            int val1 = 1e7, val2 = 1e7;
            if (j - num[i] >= 0)
                val1 = 1 + prev[j - num[i]];
            val2 = prev[j];

            prev[j] = std::min(val1, val2);
        }
    }

    return prev[n];
        
    }
};