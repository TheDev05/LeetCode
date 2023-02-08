class Solution {
public:   
int getCount(int val, int temp, int n)
{
    if (val == n)
        return 0;

    int val1 = 1e5, val2 = 1e5;

    if (val + temp <= n)
        val2 = 1 + getCount(val + temp, temp, n);
    if (temp != val)
        val1 = 1 + getCount(val, val, n);

    return std::min(val1, val2);
}

    int minSteps(int n) {
        
    if(n==1) return 0;
    return 1 + getCount(1, 1, n);
   
    }
};