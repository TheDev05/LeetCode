class Solution {
public:
    bool isValid(long long mid, std::vector<int> &num, int hours)
    {
        int count = 0;
        for (int i = 0; i < num.size(); i++)
        {
            count += ceil((double)num[i] / mid);
        }

        if (count > hours)
            return false;

        return true;
    }

    int minEatingSpeed(vector<int>& num, int hours) {

    int low = 1;
    long long high = accumulate(begin(num), end(num), (long long)0);

    int ans = 0;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isValid(mid, num, hours))
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