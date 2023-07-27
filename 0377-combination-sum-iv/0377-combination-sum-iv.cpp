class Solution {
public:
int traverse(std::vector<int> &num, std::vector<std::vector<int>> &storage, int k)
{
    if (k == 0)
        return 1;

    int val = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (k - num[i] >= 0)
        {
            if (storage[i][k - num[i]] == -1)
                storage[i][k - num[i]] = traverse(num, storage, k - num[i]);

            val += storage[i][k - num[i]];
        }
        else
            break;
    }

    return val;
}
    
    int combinationSum4(vector<int>& num, int k) {
        
    std::sort(num.begin(), num.end());
    std::vector<std::vector<int>> storage(num.size(), std::vector<int>(k + 1, -1));
    return traverse(num, storage, k);
        
    }
};