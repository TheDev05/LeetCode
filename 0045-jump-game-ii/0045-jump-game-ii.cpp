class Solution {
public:
 
    int jump(vector<int>& num) {
    std::vector<int> storage(num.size(), 0);
    for (int i = num.size() - 2; i >= 0; i--)
    {
        int val = 1e5;
        for (int j = 1; j <= num[i]; j++)
        {
            if (i + j < num.size())
            {
                val = std::min(val, storage[i+j]);
            }
            else
                break;
        }

        storage[i] = 1 + val;
    }

    return storage[0]; 
        
    }
};