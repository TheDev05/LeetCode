class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& num, int k) {
    
    int count = 0, prod = 1, index = 0;
    for (int i = 0; i < num.size(); i++)
    {
        prod *= num[i];

        while (prod >= k && index < i)
        {
            prod /= num[index++];
        }

        if (prod < k)
            count += (i - index);
    }

    for (auto i : num)
        if (i < k)
            count++;

    return count;

    }
};