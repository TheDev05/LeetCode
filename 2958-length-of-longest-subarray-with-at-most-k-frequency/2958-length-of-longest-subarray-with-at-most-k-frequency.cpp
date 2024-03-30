class Solution {
public:
    int maxSubarrayLength(vector<int>&num, int k) {
        
    std::unordered_map<int, int> data;

    int res = 0, index = 0;
    for (int i = 0; i < num.size(); i++)
    {
        data[num[i]]++;
        while (data[num[i]] > k)
        {
            if (--data[num[index]] == 0)
                data.erase(num[index]);

            index++;
        }

        res = std::max(res, (i - index) + 1);
    }

    return res;
        
    }
};