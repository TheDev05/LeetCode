class Solution {
public:
void traverse(int n, int &max, int prod, int sum, int index)
{
    if (index >= n)
        return;
    
    if (sum == n)
    {
        max = std::max(max, prod);
        return;
    }

    if (sum + index <= n)
    {
        prod *= index;
        traverse(n, max, prod, sum + index, index);
        prod /= index;
    }
    else
        return;

    traverse(n, max, prod, sum, index + 1);
}
    
    int integerBreak(int n) {
        
    int max = 0;
    traverse(n, max, 1, 0, 1);

    return max;        
    }
};