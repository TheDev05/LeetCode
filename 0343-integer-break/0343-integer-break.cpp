class Solution {
public:
int getCount(int n, int k, int index)
{
    if (n == 0 || index >= k)
        return 1;

    int val1 = 0, val2 = 0;
    if (n - index >= 0)
        val1 = index * getCount(n - index, k, index);
    val2 = getCount(n, k, index + 1);

    return std::max(val1, val2);
}

    int integerBreak(int n) {
    return getCount(n, n, 1);
        
    }
};