class Solution {
public:
    long long maximumSubarraySum(vector<int>& num, int k) {
    
    std::map<int, int> data;
    long long sum = 0, index = 0, max = 0;

    for (int i = 0; i < num.size(); i++)
    {
        if (i < k)
        {
            sum += num[i];
            data[num[i]]++;
        }
        else
        {
            sum += num[i];
            sum -= num[index];

            data[num[i]]++;
            if (--data[num[index]] == 0)
                data.erase(num[index]);

            index++;
        }

        if ((i - index) + 1 == k && data.size() == k)
            max = std::max(max, sum);
    }

    return max;

    }
};