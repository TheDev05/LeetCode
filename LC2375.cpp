#include <bits/stdc++.h>
using namespace std;

int getCode(std::string text, std::vector<int> &num, std::set<int> &data, int index)
{
    if (index >= text.size())
        return 1;

    if (text[index] == 'I')
    {
        auto it = data.end();
        it--;

        int max = *it;
        for (int i = 0; max < 10; i++)
        {
            max++;
            data.insert(max);
            num.push_back(max);

            if (getCode(text, num, data, index + 1))
            {
                return 1;
            }
            else
            {
                data.erase(max);
                num.pop_back();
            }
        }
    }
    else
    {
        int temp = num.back() - 1;
        if (data.count(temp) == false)
        {
            data.insert(temp);
            num.push_back(temp);

            if (getCode(text, num, data, index + 1))
                return 1;
            else
            {
                data.erase(temp);
                num.pop_back();

                return 0;
            }
        }
        else
            return 0;
    }

    return 0;
}

int main()
{
    std::string text;
    std::cin >> text;

    int count = 1;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == 'D')
            count++;
        else
            break;
    }

    std::vector<int> num;
    std::set<int> data;

    num.push_back(count);
    data.insert(count);

    getCode(text, num, data, 0);

    std::string result;
    for (auto i : num)
        result += to_string(i);

    std::cout << result;
}