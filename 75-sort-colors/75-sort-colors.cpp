class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> data;

        for (int i = 0; i < n; i++)
        {
            data[nums[i]]++;
        }

        nums.clear();
        
        for(auto j: data)
        {
            for (int i = 0; i < j.second; i++)
            {
                nums.push_back(j.first);
            }
            
        }
    }
};