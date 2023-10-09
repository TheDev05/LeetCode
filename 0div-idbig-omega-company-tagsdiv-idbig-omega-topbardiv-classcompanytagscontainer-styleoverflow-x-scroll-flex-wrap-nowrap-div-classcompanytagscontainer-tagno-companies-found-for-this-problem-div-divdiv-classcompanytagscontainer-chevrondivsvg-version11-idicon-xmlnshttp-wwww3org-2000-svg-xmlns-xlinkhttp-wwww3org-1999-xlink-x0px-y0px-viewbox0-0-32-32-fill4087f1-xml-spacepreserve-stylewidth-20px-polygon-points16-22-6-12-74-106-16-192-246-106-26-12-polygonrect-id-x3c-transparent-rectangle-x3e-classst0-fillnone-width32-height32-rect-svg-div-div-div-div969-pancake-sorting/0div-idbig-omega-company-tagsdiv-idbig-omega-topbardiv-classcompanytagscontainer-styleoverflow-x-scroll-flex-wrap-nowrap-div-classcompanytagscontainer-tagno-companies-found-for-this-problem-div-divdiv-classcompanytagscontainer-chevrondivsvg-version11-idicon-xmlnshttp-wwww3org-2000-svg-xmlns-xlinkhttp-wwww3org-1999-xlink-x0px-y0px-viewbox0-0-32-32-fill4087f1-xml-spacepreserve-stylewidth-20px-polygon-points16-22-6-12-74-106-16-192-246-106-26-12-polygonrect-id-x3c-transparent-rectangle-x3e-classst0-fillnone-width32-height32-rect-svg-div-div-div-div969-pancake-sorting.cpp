class Solution {
public:
    vector<int> pancakeSort(vector<int>& num) {
        
    if (is_sorted(num.begin(), num.end()))
        return {};
        
    int n = num.size();

    std::vector<int> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (num[j] == n - i)
            {
                reverse(num.begin(), num.begin() + j + 1);
                reverse(num.begin(), num.begin() + (n - i));

                res.push_back(j + 1);
                res.push_back(n - i);

                break;
            }
        }
    }
        
    return res;
    }
};