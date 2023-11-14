class Solution {
public:
    int countPalindromicSubsequence(string text) {
        
    std::map<char, std::pair<int, int>> data;
    for (int i = 0; i < text.size(); i++)
    {
        if (data.count(text[i]))
            data[text[i]].second = i;
        else
            data[text[i]].first = i;
    }

    int count = 0;
    for (auto i : data)
    {
        std::set<char> temp;
        for (int j = i.second.first + 1; j < i.second.second; j++)
            temp.insert(text[j]);

        count += temp.size();
    }

    return count;        
    }
};