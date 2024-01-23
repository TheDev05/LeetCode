class Solution {
public:
    int minPathSum(vector<vector<int>>& num) {
        
    std::vector<int> first(num[0].size(), 0), second(num[0].size(), INT_MAX);
    second[num[0].size() - 1] = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = num[0].size() - 1; j >= 0; j--)
        {
            int val1 = INT_MAX, val2 = 0;
            if (j + 1 < num[0].size())
                val1 = first[j + 1];
            val2 = second[j];

            first[j] = num[i][j] + std::min(val1, val2);
        }

        second = first;
    }

    return first[0];     
        
    }
};