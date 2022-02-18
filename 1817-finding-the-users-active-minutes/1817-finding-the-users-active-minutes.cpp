/*
 * @lc app=leetcode id=1817 lang=cpp
 *
 * [1817] Finding the Users Active Minutes
 */

// @lc code=start
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        map<int, set<int>> data;
        for (int i = 0; i < logs.size(); i++)
        {
            data[logs[i][0]].insert(logs[i][1]);
        }

        map<int, int> atom;
        for (auto i : data)
        {
            atom[i.second.size()]++;
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(atom[i + 1]);
        }

        return(result);
    }
};
// @lc code=end
