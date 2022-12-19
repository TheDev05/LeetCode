#include <bits/stdc++.h>
using namespace std;

bool getText(std::set<string> data, std::string &temp)
{
    if (temp.size() == data.size())
    {
        if (data.count(temp) == false)
            return true;

        return false;
    }

    temp += '0';
    if (getText(data, temp))
        return true;

    temp.erase(temp.size() - 1);
    temp += '1';

    if (getText(data, temp))
        return true;

    temp.erase(temp.size() - 1);
    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<string> num(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> num[i];
    }

    std::set<string> data;
    for (auto i : num)
        data.insert(i);

    std::string temp;
    getText(data, temp);

    std::cout << temp << '\n';
}