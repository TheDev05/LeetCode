#include <bits/stdc++.h>
using namespace std;

int getStrings(std::string text, std::string temp, std::vector<std::string> &num, int n, int index)
{
    if (temp.size() == n)
    {
        num.push_back(temp);
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        if (temp.size() == 0 || text[i] != temp[temp.size() - 1])
        {
            temp += text[i];
            getStrings(text, temp, num, n, index);
            temp.erase(temp.size() - 1);
        }
    }

    return 0;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::string text = "abc", temp;
    std::vector<string> num;

    getStrings(text, temp, num, n, 0);

    std::cout << num[k - 1] << '\n';
}