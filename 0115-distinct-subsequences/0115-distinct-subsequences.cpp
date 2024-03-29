class Solution {
public:
    int numDistinct(string text1, string text2) {
        
    std::vector<int> prev(text2.size() + 1, 0);
    prev[prev.size() - 1] = 1;

    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < prev.size() - 1; j++)
        {
            long long val1 = 0, val2 = 0;
            if (text1[i] == text2[j])
            {
                val1 = prev[j + 1];
                val2 = prev[j];
            }
            else
                val2 = prev[j];

            prev[j] = val1 + val2;
        }
    }

   return prev[0];
                                          
    }
};