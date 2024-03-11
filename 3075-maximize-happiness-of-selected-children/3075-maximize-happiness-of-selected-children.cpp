class Solution {
public:
    long long maximumHappinessSum(vector<int>& num, int k) {
        
    ranges::sort(num);

    long long sum = 0, temp = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] - temp > 0 && k)
            sum += num[i] - temp, k--;

        temp++;
    }

    return sum;  
        
    }
};