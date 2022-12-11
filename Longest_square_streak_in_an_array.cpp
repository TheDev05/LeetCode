#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    map<int, int> data;

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];

        double val = sqrt(nums[i]);
        if (ceil(val) == floor(val))
        {
            data[nums[i]] = 0;
        }
    }

    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (data.count(nums[i]))
        {
            int val = sqrt(nums[i]);
            if (data.count(val))
            {
                data[val] += data[nums[i]] + 1;
            }
        }
    }

    int max = INT_MIN;
    for (auto i : data)
    {
        std::cout << i.first << " " << i.second << '\n';
        max = std::max(max, i.second);
    }

    std::cout << max;
    // return (max);
}