class Solution {
public:
    int rob(vector<int>& num) {
    std::vector<int> storage(num.size() + 1, 0);
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        int val1 = 0, val2 = 0;
        for (int j = i + 2; j < num.size(); j++)
        {
            val1 = std::max(val1, storage[j]);
        }

        val2 = storage[i + 1];

        storage[i] = std::max(val1 + num[i], val2);
    }

    return storage[0];  
    }
};