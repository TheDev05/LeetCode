#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> capacity(n), storage(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> capacity[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> storage[i];
    }

    int extra;
    std::cin >> extra;

    std::vector<int> delta;
    for (int i = 0; i < n; i++)
    {
        delta.push_back(capacity[i] - storage[i]);
    }

    sort(delta.begin(), delta.end());

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (delta[i] > 0)
        {
            if (extra >= delta[i])
            {
                extra -= delta[i];
                delta[i] = 0;
            }
        }

        if (delta == 0)
            count++;
    }

    std::cout << count << '\n';
}