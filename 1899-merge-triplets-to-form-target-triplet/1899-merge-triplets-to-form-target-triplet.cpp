class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& num, vector<int>& data) {
    bool ok1 = false, ok2 = false, ok3 = false;
    for (int i = 0; i < num.size(); i++)
    {
        if (data[0] == num[i][0] && data[1] >= num[i][1] && data[2] >= num[i][2])
            ok1 = true;

        if (data[1] == num[i][1] && data[0] >= num[i][0] && data[2] >= num[i][2])
            ok2 = true;

        if (data[2] == num[i][2] && data[0] >= num[i][0] && data[1] >= num[i][1])
            ok3 = true;
    }

    return (ok1 & ok2 & ok3);    
    }
};