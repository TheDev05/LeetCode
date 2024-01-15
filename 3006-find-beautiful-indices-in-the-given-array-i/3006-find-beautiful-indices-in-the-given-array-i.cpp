class Solution {
public:
    void traverse(std::string text, std::string a, std::set<int> &data)
    {
        std::string temp;
        for (int i = 0; i < a.size(); i++)
        {
            temp += text[i];
        }

        if (temp == a)
            data.insert(0);

        for (int i = a.size(); i < text.size(); i++)
        {
            temp.erase(temp.begin());
            temp += text[i];

            if (temp == a)
                data.insert((i - a.size()) + 1);
        }
    }

    vector<int> beautifulIndices(string text, string a, string b, int k) {
        
    std::set<int> data1, data2;
    traverse(text, a, data1);
    traverse(text, b, data2);

    std::vector<int> res;
    for (auto i : data1)
    {
        auto it = data2.upper_bound(i);
        int delta = INT_MAX;

        if (it != data2.end())
            delta = std::min(delta, abs(i - *it));

        if (it != data2.begin())
        {
            it--;
            delta = std::min(delta, abs(i - *it));
        }

        if (delta <= k)
            res.push_back(i);
    } 
        
    return res;
    }
};

// 