#include <bits/stdc++.h>
using namespace std;

int getMax(std::vector<int> &num, std::vector<int> &storage, int index, int &sum)
{
    if (index >= num.size())
        return 0;

    if (storage[index] == 0)
    {
        int max = 0;
        for (int i = index + 2; i < num.size(); i++)
        {
            max = std::max(max, getMax(num, storage, i, sum));
        }

        storage[index] = max + num[index];
    }

    sum = std::max(sum, storage[index]);
    return storage[index];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::vector<int> storage(n, 0);
    if (nums.size() == 1)
        return nums[0];

    int max = INT_MIN;

    getMax(nums, storage, 0, max);
    getMax(nums, storage, 1, max);

    std::cout << max;
}