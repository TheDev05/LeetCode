class Solution {
public:
    
    int findLength(vector<int>& num1, vector<int>& num2) {
    std::vector<std::vector<int>> storage(num1.size(), std::vector<int>(num2.size(), 0));

    int max = 0;
    for (int i = 0; i < num1.size(); i++)
    {
        for (int j = 0; j < num2.size(); j++)
        {
            if (num1[i] == num2[j])
            {
                storage[i][j] = 1;
                if (i > 0 && j > 0)
                    storage[i][j] += storage[i - 1][j - 1];

                max = std::max(max, storage[i][j]);
            }
        }
    }

    return max;  
    }
};