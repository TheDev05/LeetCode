class Solution {
public:
int getCount(std::vector<int> &num, int k, std::vector<int> &sessions, int &min, int index)
{
    if (index >= num.size())
    {
        min = std::min(min, (int)sessions.size());
        return 0;
    }

    if (sessions.size() > min)
        return 0;

    for (int i = 0; i < sessions.size(); i++)
    {
        if (sessions[i] + num[index] <= k)
        {
            sessions[i] += num[index];
            getCount(num, k, sessions, min, index + 1);
            sessions[i] -= num[index];
        }
    }

    sessions.push_back(num[index]);
    getCount(num, k, sessions, min, index + 1);
    sessions.pop_back();

    return 0;
}

    int minSessions(vector<int>& num, int k) {

    int min = INT_MAX;
    std::vector<int> sessions;

    getCount(num, k, sessions, min, 0);
    return min;

    }
};