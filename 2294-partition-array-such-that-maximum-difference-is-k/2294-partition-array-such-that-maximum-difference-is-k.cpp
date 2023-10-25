class Solution {
public:
    int partitionArray(vector<int>& num, int k) {        
    sort(num.begin(), num.end());

    int count = 1, delta = 0;
    for (int i = 0; i < num.size() - 1; i++)
    {
        delta += abs(num[i] - num[i + 1]);

        if (delta > k)
            count++, delta = 0;
    }

    return count;        
    }
};
