class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
    std::vector<int> res;
    for (int i = 1; i <= 9; i++)
    {
        int temp = i;
        while (temp <= high)
        {
            if (temp >= low)
                res.push_back(temp);
            if ((temp % 10) + 1 < 10)
                temp = (temp * 10) + ((temp % 10) + 1);
            else
                break;
        }
    }
    
    sort(begin(res), end(res));
    return res;
        
    }
};