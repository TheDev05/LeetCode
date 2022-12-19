#include <bits/stdc++.h>
using namespace std;

int getCount(std::vector<int> &num, std::vector<int> &temp, std::set<int> &data, int index, int &count)
{
    if (temp.size() == num.size())
    {
        count++;
        return 0;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (data.count(num[i]) == false && (num[i] % (temp.size() + 1) == 0 || (temp.size() + 1) % num[i] == 0))
        {
            temp.push_back(num[i]);
            data.insert(num[i]);

            getCount(num, temp, data, i + 1, count);

            temp.pop_back();
            data.erase(num[i]);
        }
    }

    return 0;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> num(n);
    std::iota(num.begin(), num.end(), 1);

    std::set<int> data;
    std::vector<int> temp;

    int count = 0;
    getCount(num, temp, data, 0, count);

    std::cout << count << '\n';
}