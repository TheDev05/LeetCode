class Solution {
public:
    string clearStars(string text) {

    std::map<char, set<int, greater<>>> data;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '*')
        {
            auto it = data.begin()->second.begin();

            text[*it] = '$';
            data.begin()->second.erase(it);

            if (data.begin()->second.empty())
                data.erase(data.begin()->first);
        }
        else
        {
            data[text[i]].insert(i);
        }
    }

    std::string res;
    for (auto i : text)
        if (i != '*' && i != '$')
            res += i;

    return res; 
           
    }
};