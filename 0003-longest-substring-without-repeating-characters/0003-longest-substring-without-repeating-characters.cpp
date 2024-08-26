class Solution {
public:
    int lengthOfLongestSubstring(string text) {
    std::map<char, int> data;

    int max = 0, index = 0;
    for (int i = 0; i < text.size(); i++)
    {
        data[text[i]]++;

        while (data[text[i]] > 1)
        {
            if(--data[text[index]] == 0)
                data.erase(text[index]);
            index++;
        }

        max = std::max(max, (int)data.size());
    }

    return max;        
    }
};