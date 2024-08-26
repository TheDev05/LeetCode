class Solution {
public:
    vector<int> searchRange(vector<int>& num, int k) {

    int left = 0, right = num.size() - 1;
    int start = -1, end = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (num[mid] == k)
        {
            if (mid != 0 && num[mid - 1] == k)
                right = mid - 1;
            else
            {
                start = mid;
                break;
            }
        }
        else if (num[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }

    left = 0, right = num.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (num[mid] == k)
        {
            if (mid != num.size() - 1 && num[mid + 1] == k)
                left = mid + 1;
            else
            {
                end = mid;
                break;
            }
        }
        else if (num[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    } 

    std::vector<int>res={start, end};
    return res;       
    }
};