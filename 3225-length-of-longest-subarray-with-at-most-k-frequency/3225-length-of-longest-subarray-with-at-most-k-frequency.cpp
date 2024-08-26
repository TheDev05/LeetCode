class Solution {
public:
    int maxSubarrayLength(vector<int>& num, int k) {
    std::map<int, int> data;

    int index = 0, max = 0;
    for (int i = 0; i < num.size(); i++)
    {
        data[num[i]]++;

        while (data[num[i]] > k)
        {
            data[num[index]]--;
            index++;
        }

        max = std::max(max, (i - index) + 1);
    }

    return max;       
    }
};