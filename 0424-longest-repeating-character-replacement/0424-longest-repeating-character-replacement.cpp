class Solution {
public:
    int characterReplacement(string text, int k) {
        
    std::map<char, int> data;
    std::map<int, std::set<char>, greater<int>> inox;

    int count = 0, index = 0, res = 0;
    for (int i = 0; i < text.size(); i++)
    {
        data[text[i]]++;

        if (data[text[i]] - 1 > 0)
            inox[data[text[i]] - 1].erase(text[i]);

        inox[data[text[i]]].insert(text[i]);

        while (((i - index) + 1) - (inox.begin()->first) > k)
        {
            inox[data[text[index]]].erase(text[index]);
            if (inox[data[text[index]]].empty())
                inox.erase(data[text[index]]);

            if (--data[text[index]] == 0)
                data.erase(text[index]);

            if (data.contains(text[index]))
                inox[data[text[index]]].insert(text[index]);

            index++;
        }

        res = std::max(res, (i - index) + 1);
    }

    return res; 
        
    }
};
