class Solution {
public:
    int findLength(vector<int>& num1, vector<int>& num2) {
        
    int max = INT_MIN, n=num1.size(), m=num2.size();
    std::vector<int> prev(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size() - 1; j++)
        {
            if (num1[i] == num2[j])
                prev[j] = 1 + prev[j + 1];
            else
                prev[j] = 0;

            max = std::max(max, prev[j]);
        }
    }

    return max;
        
    }
};