class Solution {
public:
    bool canConstruct(string text, int k) {
        
    std::map<char, int> data;
    for (auto i : text)
        data[i]++;

    int count = 0;
    for (auto i : data)
        if (i.second & 1)
            count++;

    if (count == 0)
        count = 1;

    if (k >= count && k <= text.size())
       return true;
    return false;
       
    }
};
