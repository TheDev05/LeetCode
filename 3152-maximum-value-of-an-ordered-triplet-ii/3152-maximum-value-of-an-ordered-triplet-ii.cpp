class Solution {
public:
    long long maximumTripletValue(vector<int>& num) {

    std::set<long long> left;
    std::map<long long, long long> right;

    for (auto i : num)
        right[i]++;

    long long result = 0;
    for (int i = 0; i < num.size(); i++)
    {
        left.insert(num[i]);
        if (--right[num[i]] == 0)
            right.erase(num[i]);

        if (right.size() && *left.rbegin() > num[i])
            result = std::max(result, (*left.rbegin() - num[i]) * right.rbegin()->first);

    }

    return result;

    }
};