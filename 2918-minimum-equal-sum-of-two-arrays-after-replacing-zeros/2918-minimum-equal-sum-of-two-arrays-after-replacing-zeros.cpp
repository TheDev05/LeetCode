class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2) {
        
    int count1 = 0, count2 = 0;
    for (auto i : num1)
        if (i == 0)
            count1++;

    for (auto i : num2)
        if (i == 0)
            count2++;

    long long sum1 = 0, sum2 = 0;
    sum1 = accumulate(begin(num1), end(num1), (long long)0);
    sum2 = accumulate(begin(num2), end(num2), (long long)0);

    if (sum1 == sum2 && std::max(count1, count2) == 0)
        return sum1;

    if (count1 == 0 && count2 == 0)
        return -1;

    if (count1)
        sum1 += (count1 - 1);
    if (count2)
        sum2 += (count2 - 1);

    if (count1 == 0)
    {
        if (sum2 < sum1)
            return sum1;
        return -1;
    }

    if (count2 == 0)
    {
        if (sum1 < sum2)
            return sum2;
        return -1;
    }

    return std::max(sum1, sum2) + 1;        
    }
};