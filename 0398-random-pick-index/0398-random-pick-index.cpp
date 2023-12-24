class Solution {
public:
    std::map<int, std::vector<int>>idx;
    Solution(vector<int>& nums) {
     for(int i=0; i<nums.size(); i++) idx[nums[i]].push_back(i);   
    }
    
    int pick(int target) {
        return idx[target][rand() % idx[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */