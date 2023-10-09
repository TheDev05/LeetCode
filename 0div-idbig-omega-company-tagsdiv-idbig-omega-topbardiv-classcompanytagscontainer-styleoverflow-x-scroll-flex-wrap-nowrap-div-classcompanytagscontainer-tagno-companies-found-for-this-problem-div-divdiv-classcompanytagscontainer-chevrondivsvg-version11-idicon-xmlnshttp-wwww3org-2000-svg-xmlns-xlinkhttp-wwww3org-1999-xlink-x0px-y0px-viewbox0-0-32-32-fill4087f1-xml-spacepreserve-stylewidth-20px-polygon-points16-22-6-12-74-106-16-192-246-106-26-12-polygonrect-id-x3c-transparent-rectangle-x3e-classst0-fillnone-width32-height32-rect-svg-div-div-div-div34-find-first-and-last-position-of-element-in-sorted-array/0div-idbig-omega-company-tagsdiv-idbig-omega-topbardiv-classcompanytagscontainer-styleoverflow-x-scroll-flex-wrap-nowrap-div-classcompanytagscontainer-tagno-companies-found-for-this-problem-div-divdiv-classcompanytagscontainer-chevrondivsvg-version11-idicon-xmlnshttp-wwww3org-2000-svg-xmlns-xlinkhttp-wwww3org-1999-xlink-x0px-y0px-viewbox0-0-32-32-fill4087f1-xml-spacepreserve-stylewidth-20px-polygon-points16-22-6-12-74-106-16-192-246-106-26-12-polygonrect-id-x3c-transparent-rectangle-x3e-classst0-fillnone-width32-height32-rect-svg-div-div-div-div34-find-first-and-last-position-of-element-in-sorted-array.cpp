class Solution {
public:
int binSearch(std::vector<int> &num, int target, bool ok)
{
    int left = 0, right = num.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (num[mid] == target)
        {
            if (ok)
                if (mid && num[mid - 1] == target)
                    right = mid - 1;
                else
                    return mid;

            if (!ok)
                if (mid != num.size() - 1 && num[mid + 1] == target)
                    left = mid + 1;
                else
                    return mid;
        }
        else if (num[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
    
    vector<int> searchRange(vector<int>& num, int target) {
        
    int left = binSearch(num, target, true);
    int right = binSearch(num, target, false);
        
    return {left, right};
    }
};