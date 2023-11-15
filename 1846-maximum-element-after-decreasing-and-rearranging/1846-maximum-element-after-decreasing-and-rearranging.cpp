class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& num) {
    sort(begin(num), end(num));
    num[0] = 1;

    for (int i = 1; i < num.size(); i++)
    {
        if (num[i] > num[i - 1])
            num[i] = num[i - 1] + 1;
    }
        
    return *max_element(begin(num), end(num));
    }
};