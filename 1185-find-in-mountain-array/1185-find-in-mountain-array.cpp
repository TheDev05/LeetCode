/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int getPeak(MountainArray &num)
    {
        int left = 0, right = num.length();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid != 0 && mid != num.length() && num.get(mid - 1) < num.get(mid) && num.get(mid + 1) < num.get(mid))
                return mid;
            if (mid != 0 && num.get(mid - 1) < num.get(mid))
                left = mid;
            if (mid != num.length() - 1 && num.get(mid + 1) < num.get(mid))
                right = mid;
        }

        return 0;
    }

    int bSearch(MountainArray &num, int target, int peak, bool ok)
    {
        int left = 0, right = peak;
        if (ok == false)
            left = peak, right = num.length() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (num.get(mid) == target)
                return mid;
            else if (num.get(mid) > target)
            {
                if (ok)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (ok)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &num)
    {

        int peak = getPeak(num);
        int index = bSearch(num, target, peak, true);
        if (index == -1)
            index = bSearch(num, target, peak, false);

        return index;
    }
};