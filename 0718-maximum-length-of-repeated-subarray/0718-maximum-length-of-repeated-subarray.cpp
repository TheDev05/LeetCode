class Solution {
public:
    
    int findLength(vector<int>& num1, vector<int>& num2) {
    std::vector<int> prev(num2.size() + 1, 0);

    int max = 0;
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size() - 1; j++)
        {
            int val1 = 0;
            if (num1[i] == num2[j])
                val1 = 1 + prev[j + 1];
            else
                prev[j] = 0;

            prev[j] = val1;
            max = std::max(max, prev[j]);
        }
    }

    return max;
        
    }
};