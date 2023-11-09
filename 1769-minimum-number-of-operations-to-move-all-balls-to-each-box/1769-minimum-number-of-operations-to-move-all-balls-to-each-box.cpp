class Solution {
public:
    vector<int> minOperations(string text) {
        
    std::set<int> idx;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '1')
            idx.insert(i);
    }

    std::vector<int> res;
    for (int i = 0; i < text.size(); i++)
    {
        int sum = 0;
        for (auto j : idx)
            if (j != i)
                sum += abs(i - j);

        res.push_back(sum);
    }

    return res;       
    }
};