class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left=0,right=nums.size()-1;
        int key=target;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(key==nums[mid])return(mid);
            else if(nums[mid]<key)left=mid+1;
            else right=mid-1;
        }
        
        
        return(left);
    }
};