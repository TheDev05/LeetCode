class Solution {
public:
    
set<vector<int>> data;
void getSet(vector<int> num, vector<int> temp, vector<vector<int>> *res, int index)
{
    if (index >= num.size())
    {
        sort(temp.begin(), temp.end());
        if (data.count(temp) == false)
        {
            res->push_back(temp);
            data.insert(temp);
        }

        return;
    }

    temp.push_back(num[index]);
    getSet(num, temp, res, index + 1);

    temp.pop_back();
    getSet(num, temp, res, index + 1);
}

    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
    vector<int>temp;
    vector<vector<int>> res;

    getSet(nums, temp, &res, 0);

    return (res);
    }
};