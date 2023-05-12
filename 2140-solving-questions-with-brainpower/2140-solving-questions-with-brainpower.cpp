class Solution {
public:
long long traverse(std::vector<std::vector<int>> &num, std::vector<long long> &store, int index)
{
    if (index >= num.size())
        return 0;

    if (store[index] == -1)
    {
        long long sum1 = num[index][0] + traverse(num, store, index + num[index][1] + 1);
        long long sum2 = traverse(num, store, index + 1);

        store[index] = std::max(sum1, sum2);
    }

    return store[index];
}
    
    long long mostPoints(vector<vector<int>>& num) {
        
    std::vector<long long> store(num.size(), -1);
    return traverse(num, store, 0);   
        
    }
};