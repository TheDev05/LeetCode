class Solution {
public:
    bool canPartition(vector<int>& num) {
        
    int sum = accumulate(begin(num), end(num), 0);
    if (sum & 1)
        return false;

    sum /= 2;

    std::vector<int> first(sum + 1, 0), second(sum + 1, 0);
    second[0] = 1;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < first.size(); j++)
        {
            int val1 = 0, val2 = 0;
            if (j - num[i] >= 0)
                val1 = second[j - num[i]];
            val2 = second[j];

            first[j] = val1 | val2;
        }

        second = first;
    }

    return first.back(); 
        
    }
};