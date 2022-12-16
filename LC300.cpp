#include <bits/stdc++.h>
using namespace std;

int fillStore(std::vector<int> &num, std::vector<int> &storage, int index)
{
    if (index >= num.size())
        return 0;

    if (storage[index] == -1)
    {
        int max = 0;
        for (int i = index + 1; i < num.size(); i++)
        {
            if (num[i] > num[index])
            {
                if (storage[i] == -1)
                {
                    storage[i] = 1 + fillStore(num, storage, i);
                }

                max = std::max(max, storage[i]);
            }
        }

        storage[index] = max;
    }

    return storage[index];
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n), storage(n, -1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (storage[i] == -1)
        {
            storage[i] = 1 + fillStore(num, storage, i);
        }

        max = std::max(max, storage[i]);
    }

    std::cout << max << '\n';
}