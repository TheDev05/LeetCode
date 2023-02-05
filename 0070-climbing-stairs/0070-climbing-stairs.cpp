class Solution {
public:
    int climbStairs(int n) {
    std::vector<int> storage(n + 1, 0);
    storage[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int val1 = 0, val2 = 0;
        if (i + 1 <= n)
            val1 = storage[i + 1];
        if (i + 2 <= n)
            val2 = storage[i + 2];

        storage[i] = val1 + val2;
    }

    return storage[0];
        
    }
};