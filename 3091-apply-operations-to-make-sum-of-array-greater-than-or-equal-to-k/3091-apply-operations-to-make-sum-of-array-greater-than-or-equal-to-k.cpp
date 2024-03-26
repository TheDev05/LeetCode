class Solution {
public:
    int minOperations(int k) {

    int sum = 1, count = 0, min = INT_MAX;
    while (sum < k)
    {
        int temp = ceil(((double)k - sum) / sum);
        count = (sum - 1);

        min = std::min(min, temp + count);
        sum++;
    }

    if(min == INT_MAX) return 0;
    return min; 

    }
};