class Solution {
public:
    int minSubArrayLen(int target, vector<int>& num) {
    int min = INT_MAX, sum = 0, index = 0;
    for (int i = 0; i < num.size(); i++)
    {
        sum += num[i];
        while (sum > target)
        {
            min = std::min(min, (i - index) + 1);

            sum -= num[index];
            index++;
        }

        if (sum == target)
            min = std::min(min, (i - index) + 1);
    }
        
    if (min == INT_MAX)
        min = 0;

    return min;        
    }
};