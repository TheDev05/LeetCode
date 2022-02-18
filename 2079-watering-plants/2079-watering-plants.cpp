/*
 * @lc app=leetcode id=2079 lang=cpp
 *
 * [2079] Watering Plants
 */

// @lc code=start
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int river = -1, container = capacity, sum = 0;
        for (int i = 0; i < plants.size(); i++)
        {
            if (container >= plants[i])
            {
                container = container - plants[i];
            }
            else
            {
                sum += ((i - 1) - river) * 2;
                container = capacity - plants[i];
            }

            sum++;
        }

        return (sum);
    }
};
// @lc code=end
