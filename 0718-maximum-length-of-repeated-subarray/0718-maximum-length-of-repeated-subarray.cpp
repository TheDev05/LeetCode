class Solution {
public:
    int findLength(vector<int>& num1, vector<int>& num2) {
        
    int max = INT_MIN, n=num1.size(), m=num2.size();
    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(m + 1, 0));
        
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            if (num1[i] == num2[j])
                storage[i][j] = 1 + storage[i + 1][j + 1];
            else
                storage[i][j] = 0;

            max = std::max(max, storage[i][j]);
        }
    }

    return max;
        
    }
};