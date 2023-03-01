class Solution {
public:
int traverse(int sum, int copy, int target)
{
    if (sum > target)
        return 1e5;
    if (sum == target)
        return 0;

    int val1 = 1e5, val2 = 1e5;
    if (copy != sum)
        val1 = 1 + traverse(sum, sum, target);
    val2 = 1 + traverse(sum + copy, copy, target);

    return std::min(val1, val2);
}
    
    int minSteps(int n) {
    if (n == 1)
        return 0;
        
    return 1 + traverse(1, 1, n);
        
    }
};