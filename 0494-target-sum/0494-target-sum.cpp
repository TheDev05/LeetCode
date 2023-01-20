class Solution {
public:
    int getCount(std::vector<int> &num, int k, int index)
{
    if (index >= num.size())
        return (k == 0) ? 1 : 0;

    int val1 = getCount(num, k - num[index], index + 1);
    int val2 = getCount(num, k + num[index], index + 1);

    return val1 + val2;
}
    
    int findTargetSumWays(vector<int>& num, int k) {
        return getCount(num, k, 0);

    }
};