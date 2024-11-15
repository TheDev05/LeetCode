class Solution {
public:
bool isValid(int mid, std::vector<int> &num, int days)
{
    int count = 1, sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] > mid)
            return false;

        if (sum + num[i] <= mid)
            sum += num[i];
        else
        {
            count++;
            sum = num[i];
        }
    }

    if (count <= days)
        return true;

    return false;
}

    int shipWithinDays(vector<int>& num, int days) {

    int low = 1;
    int high = accumulate(begin(num), end(num), 0);

    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(mid, num, days))
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