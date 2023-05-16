class Solution {
public:
int traverse(std::vector<int> &num, std::vector<int> &temp, std::vector<std::vector<int>> &store, int k, int index)
{
    if (temp.size() == k)
    {
        store.push_back(temp);
        return 0;
    }

    if (index >= num.size())
        return 0;

    if (temp.size() < k)
    {
        temp.push_back(num[index]);
        traverse(num, temp, store, k, index + 1);
        temp.pop_back();
    }

    traverse(num, temp, store, k, index + 1);
    return 0;
}
    
    vector<vector<int>> combine(int n, int k) {
    std::vector<int> num(n);
    std::iota(num.begin(), num.end(), 1);

    std::vector<std::vector<int>> store;
    std::vector<int> temp;

    traverse(num, temp, store, k, 0);
    return store;
        
    }
};