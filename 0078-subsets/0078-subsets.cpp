class Solution {
public:
    void traverse(std::vector<int>&nums,std::vector<int>&temp, std::vector<std::vector<int>>&ans, int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        traverse(nums, temp, ans, index+1);
        
        temp.pop_back();
        traverse(nums, temp, ans, index+1);
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        std::vector<std::vector<int>>ans;
        std::vector<int>temp;
        
        traverse(nums,temp,ans,0);
        
        return ans;
    }
};