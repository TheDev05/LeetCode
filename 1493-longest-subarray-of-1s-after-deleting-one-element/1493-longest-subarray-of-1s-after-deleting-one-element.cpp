class Solution {
public:
    int longestSubarray(vector<int>& num) {
        
    int max = 0, index = 0;
    int one = 0, zero = 0;

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i])
            one++;
        else
            zero++;

        while (zero >= 2)
        {
            if (num[index])
                one--;
            else
                zero--;
                
            index++;
        }

        if (zero < 2)
            max = std::max(max, one);
    }
        
    if(max == num.size())
     max--;
        
    return max;        
    }
};