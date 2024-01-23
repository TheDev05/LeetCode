class Solution {
public:
    int minimumTotal(vector<vector<int>>& num) {
        
    if(num.size() == 1)
        return num[0][0];
        
    std::vector<int> first(num.size(), 0), second(num.size(), 0);
    second = num[num.size() - 1];

    for (int i = num.size() - 2; i >= 0; i--)
    {
        for (int j = num[i].size() - 1; j >= 0; j--)
        {
            int val1 = INT_MAX, val2 = INT_MAX;

            val1 = second[j];
            val2 = second[j + 1];

            first[j] = std::min(val1, val2) + num[i][j];
        }

        second = first;
    }

    return first.front(); 
        
    }
};