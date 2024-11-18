class Solution {
public:
    void nextPermutation(vector<int>& num) {
        
    int idx = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int delta = INT_MAX, index = i;
        for (int j = i; j < num.size(); j++)
        {
            if (num[i] < num[j] && abs(num[i] - num[j]) < delta)
            {
                delta = abs(num[i] - num[j]);
                index = j;
            }
        }

        if (delta != INT_MAX)
        {
            std::swap(num[i], num[index]);
            idx = i + 1;

            break;
        }
    }

    sort(num.begin() + idx, num.end());
    }
};