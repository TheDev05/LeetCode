class Solution {
public:
    
    int findLength(vector<int>& num1, vector<int>& num2) {
    std::vector<int> prev(num2.size(), 0);

    std::vector<std::vector<int>> storage(num1.size() + 1, std::vector<int>(num2.size() + 1, 0));

    int max = 0;
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 0;
            if (num1[i] == num2[j])
                val1 = 1 + storage[i + 1][j + 1];

            storage[i][j] = val1;
            max = std::max(max, storage[i][j]);
        }
    }

    return max; 
        
    }
};