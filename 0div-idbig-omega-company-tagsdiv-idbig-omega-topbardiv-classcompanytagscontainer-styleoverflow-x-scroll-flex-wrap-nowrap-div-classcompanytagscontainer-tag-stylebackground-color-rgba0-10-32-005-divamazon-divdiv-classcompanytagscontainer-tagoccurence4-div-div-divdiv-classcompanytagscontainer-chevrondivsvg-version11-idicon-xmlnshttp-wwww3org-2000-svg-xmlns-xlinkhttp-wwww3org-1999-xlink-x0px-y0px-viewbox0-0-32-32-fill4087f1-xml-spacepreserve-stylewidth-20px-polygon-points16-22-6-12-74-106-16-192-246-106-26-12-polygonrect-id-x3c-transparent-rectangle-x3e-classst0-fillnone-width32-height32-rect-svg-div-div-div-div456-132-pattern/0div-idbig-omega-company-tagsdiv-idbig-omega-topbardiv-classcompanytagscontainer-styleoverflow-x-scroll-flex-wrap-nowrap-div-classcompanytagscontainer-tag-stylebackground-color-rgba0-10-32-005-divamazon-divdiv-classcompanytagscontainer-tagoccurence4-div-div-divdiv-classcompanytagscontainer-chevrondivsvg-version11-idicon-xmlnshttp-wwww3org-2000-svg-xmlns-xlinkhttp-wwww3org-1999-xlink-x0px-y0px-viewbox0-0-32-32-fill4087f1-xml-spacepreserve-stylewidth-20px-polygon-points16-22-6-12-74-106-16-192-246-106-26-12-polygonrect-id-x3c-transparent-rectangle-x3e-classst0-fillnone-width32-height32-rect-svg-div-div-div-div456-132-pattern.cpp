class Solution {
public:
    bool find132pattern(vector<int>& num) {
    int n = num.size();
        
    std::map<int, int> left, right;
    bool ok = false;

    for (auto i : num)
        right[i]++;

    for (int i = 0; i < n; i++)
    {
        right[num[i]]--;
        if (right[num[i]] == 0)
            right.erase(num[i]);

        if (i > 0 && i < n - 1)
        {
            auto it1 = left.begin();
            auto it2 = right.upper_bound(it1->first);
            if (it1->first < num[i] && it2 != right.end() && it2->first < num[i])
               return true;
        }

        left[num[i]]++;
    }

    return false;        
    }
};