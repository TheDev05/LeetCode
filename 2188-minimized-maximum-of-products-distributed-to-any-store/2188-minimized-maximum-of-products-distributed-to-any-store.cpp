class Solution {
public:
    bool isValid(int mid, std::vector<int> &num, int target)
    {
        int count = 0;
        for (int i = 0; i < num.size(); i++)
        {
            count += ceil((double)num[i] / mid);
        }

        return (count > target) ? false : true;
    }

    int minimizedMaximum(int target, vector<int>& num) {
    
    int low = 1;
    int high = *max_element(begin(num), end(num));

    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(mid, num, target))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;

    }
};