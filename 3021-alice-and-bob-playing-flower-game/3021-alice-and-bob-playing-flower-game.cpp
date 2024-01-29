class Solution {
public:
    long long flowerGame(int n, int m) {
        
    int temp = n;
    n = std::min(m, n);
    m = std::max(m, temp);

    long long even = m / 2, odd = m / 2;

    if (m & 1)
        odd++;

    long long count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            count += even;
        else
            count += odd;
    }

    return count;
        
    }
};
