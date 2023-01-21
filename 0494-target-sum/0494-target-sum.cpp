class Solution {
public:
    int getCount(std::vector<int> &num, int sum, int index)
{
    if (index >= num.size())
        return (sum == 0) ? 1 : 0;

    int val1 = getCount(num, sum - num[index], index + 1);
    int val2 = getCount(num, sum, index + 1);

    return val1 + val2;
}

    int findTargetSumWays(vector<int>& num, int k) {
            int total = 0, sum = 0;
    for (auto i : num)
        total += i;

    if ((total + k) % 2 == 0)
    {
        sum = (total + k) / 2;
    }
    else if ((total - k) % 2 == 0)
    {
        sum = (total - k) / 2;
    }else return 0;

    return getCount(num, sum, 0);
    }
};