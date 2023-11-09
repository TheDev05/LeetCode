class Solution {
public:
    int maxSubArray(vector<int>& num) {
        
    int sum = 0, max = INT_MIN;
    for (int i = 0; i < num.size(); i++)
    {
        if (sum + num[i] < num[i])
            sum = num[i];
        else
            sum += num[i];
        
        max = std::max(max, sum);
    }

    return max;        
    }
};