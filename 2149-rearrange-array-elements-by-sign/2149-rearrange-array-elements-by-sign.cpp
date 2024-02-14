class Solution {
public:
    vector<int> rearrangeArray(vector<int>& num) {

    std::vector<int> pos, neg, res;
    for (auto i : num)
        if (i > 0)
            pos.push_back(i);
        else
            neg.push_back(i);

    reverse(begin(pos), end(pos));
    reverse(begin(neg), end(neg));

    res.push_back(pos.back());
    pos.pop_back();

    while (pos.size() || neg.size())
    {
        if (res.back() > 0)
        {
            if (neg.size())
                res.push_back(neg.back()),
                    neg.pop_back();
        }
        else if (pos.size())
            res.push_back(pos.back()),
                pos.pop_back();
    }

    return res;        
    }
};