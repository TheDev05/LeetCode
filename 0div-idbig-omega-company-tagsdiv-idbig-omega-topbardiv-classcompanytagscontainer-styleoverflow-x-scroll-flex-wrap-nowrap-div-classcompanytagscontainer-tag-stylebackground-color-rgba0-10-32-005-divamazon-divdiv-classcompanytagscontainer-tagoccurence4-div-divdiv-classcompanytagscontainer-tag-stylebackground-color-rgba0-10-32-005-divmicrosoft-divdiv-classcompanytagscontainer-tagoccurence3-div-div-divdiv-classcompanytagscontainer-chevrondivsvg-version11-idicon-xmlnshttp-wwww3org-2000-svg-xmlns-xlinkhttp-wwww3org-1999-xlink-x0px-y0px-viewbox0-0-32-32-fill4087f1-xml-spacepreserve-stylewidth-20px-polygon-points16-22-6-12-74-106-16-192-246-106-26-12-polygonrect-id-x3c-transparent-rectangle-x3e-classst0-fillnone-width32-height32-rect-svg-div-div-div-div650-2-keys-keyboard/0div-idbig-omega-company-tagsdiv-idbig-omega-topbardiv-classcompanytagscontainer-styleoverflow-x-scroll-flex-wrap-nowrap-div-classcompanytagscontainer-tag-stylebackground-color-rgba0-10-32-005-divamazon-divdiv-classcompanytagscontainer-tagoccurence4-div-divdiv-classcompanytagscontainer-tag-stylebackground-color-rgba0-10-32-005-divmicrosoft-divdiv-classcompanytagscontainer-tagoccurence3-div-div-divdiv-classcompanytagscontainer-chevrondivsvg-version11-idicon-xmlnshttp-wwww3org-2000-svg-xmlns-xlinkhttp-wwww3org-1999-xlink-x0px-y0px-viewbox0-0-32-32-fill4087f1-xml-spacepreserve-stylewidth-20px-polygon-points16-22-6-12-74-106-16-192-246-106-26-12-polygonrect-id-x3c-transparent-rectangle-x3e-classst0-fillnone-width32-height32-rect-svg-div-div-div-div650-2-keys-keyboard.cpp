class Solution {
public:
int traverse(int n, std::vector<std::vector<int>> &storage, int copy, int curr)
{
    if (curr == n)
        return 0;

    if (curr > n)
        return 1e5;

    if (storage[curr][copy] == -1)
    {
        int val1 = 1e5, val2 = 1e5;
        if (curr != copy)
            val1 = 1 + traverse(n, storage, curr, curr);
        if (copy)
            val2 = 1 + traverse(n, storage, copy, curr + copy);

        storage[curr][copy] = std::min(val1, val2);
    }

    return storage[curr][copy];
}
    
    int minSteps(int n) {
    std::vector<std::vector<int>> storage(n + 1, std::vector<int>(n + 1, -1));
    return traverse(n, storage, 0, 1);  
    }
};