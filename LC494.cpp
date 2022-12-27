#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, int targetSum, int sum, int index, int &count)
{
    if (index >= num.size())
    {
        if (targetSum == sum)
            count++;

        return 0;
    }

    int val1 = getCount(num, targetSum, sum + num[index], index + 1, count);
    int val2 = getCount(num, targetSum, sum - num[index], index + 1, count);

    return 0;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int targetSum, count = 0;
    std::cin >> targetSum;

    std::vector<int> storage(n, -1);
    getCount(num, targetSum, 0, 0, count);

    std::cout << count << '\n';
}