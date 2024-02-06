class Solution {
public:
    bool checkInclusion(string target, string text) {

    std::vector<int> num(26, 0);
    std::map<char, int> data, res;

    for (auto i : target)
        data[i]++, num[i - 'a']++;

    int index = 0;
    bool ok = false;

    for (int i = 0; i < text.size(); i++)
    {
        if (data.contains(text[i]))
        {
            if (--data[text[i]] == 0)
                data.erase(text[i]);
        }

        res[text[i]]++;

        while (data.empty())
        {
            if ((i - index) + 1 == target.size())
                ok |= true;

            res[text[index]]--;

            if (res[text[index]] < num[text[index] - 'a'])
                data[text[index]]++;

            if (res[text[index]] == 0)
                res.erase(text[index]);

            index++;
        }
    }

    return ok;

    }
};