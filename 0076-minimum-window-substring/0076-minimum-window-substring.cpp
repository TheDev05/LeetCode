class Solution {
public:
    string minWindow(string text, string target) {
        
    std::map<char, int> data, idx, store;

    for (auto i : target)
        data[i]++, store[i]++, idx[i] = 0;

    int index = 0, res = INT_MAX;
    int left = 0, right = 0;

    for (int i = 0; i < text.size(); i++)
    {
        if (idx.contains(text[i]))
        {
            if (data.contains(text[i]) && --data[text[i]] == 0)
                data.erase(text[i]);
            idx[text[i]]++;
        }

        if (data.empty())
        {
            while (data.empty())
            {
                if ((i - index) + 1 < res)
                {
                    res = (i - index) + 1;
                    left = index, right = i;
                }

                if (idx.contains(text[index]))
                    if (--idx[text[index]] < store[text[index]])
                        data[text[index]]++;

                index++;
            }

            if (data.empty() && (i - index) + 1 < res)
            {
                res = (i - index) + 1;
                left = index, right = i;
            }
        }
    }

    text = text.substr(left, (right - left) + 1);
    if (res == INT_MAX)
        return "";
        
    return text;  
        
    }
};