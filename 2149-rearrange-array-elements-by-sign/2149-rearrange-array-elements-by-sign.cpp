/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        set<pair<int, int>> pos;
        set<pair<int, int>> neg;

        int index = 0;
        for (auto i : nums)
        {
            if (i < 0)
            {
                neg.insert(make_pair(index, i));
            }
            else
                pos.insert(make_pair(index, i));

            index++;
        }

        vector<int> result;

        auto it = pos.begin();
        result.push_back((it)->second);
        pos.erase(it);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (result.back() > 0)
            {
                auto it = neg.begin();

                result.push_back((it)->second);
                neg.erase(it);
            }
            else
            {
                auto it = pos.begin();

                result.push_back((it)->second);
                pos.erase(it);
            }
        }

        return (result);
    }
};
// @lc code=end
