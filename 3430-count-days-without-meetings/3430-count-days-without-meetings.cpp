class Solution {
public:
    int countDays(int k, vector<vector<int>>& num) {
        
    ranges::sort(num);

    int left = num[0][0], right = num[0][1];
    for (int i = 0; i < num.size(); i++)
    {
        if (left <= num[i][0] && num[i][0] <= right)
            right = std::max(right, num[i][1]);
        else
        {
            k = k - ((right - left) + 1);

            left = num[i][0];
            right = num[i][1];
        }
    }

    k = k - ((right - left) + 1);
    return k; 

    }
};