class Solution {
public:
    string addSpaces(string text, vector<int>& spaces) {
    
    std::set<int> data;
    for (int i = 0; i < spaces.size(); i++)
        data.insert(spaces[i]);

    std::string res;
    for (int i = 0; i < text.size(); i++)
    {
        if (data.contains(i))
            res += " ";
        res += text[i];
    }

    return res;

    }
};