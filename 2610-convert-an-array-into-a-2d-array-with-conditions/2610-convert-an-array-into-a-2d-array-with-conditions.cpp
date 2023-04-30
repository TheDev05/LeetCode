class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        std::vector<std::vector<int>>result;  
        std::set<int>ignore;
        
        for(int i=0; i<nums.size(); i++)
        {
            std::vector<int>temp;
            std::set<int>exist;
            
            for(int j=0;j<nums.size();j++)
            {
                if(ignore.count(j) == false && exist.count(nums[j]) == false)
                {
                    temp.push_back(nums[j]);
                    
                    exist.insert(nums[j]);
                    ignore.insert(j);
                }
            }
            
            if(temp.size())
               result.push_back(temp);
        }
        
        return result;
    }
};