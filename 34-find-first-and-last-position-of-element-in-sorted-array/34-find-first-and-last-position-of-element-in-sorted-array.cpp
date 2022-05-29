class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int n=nums.size();
        
        int left=0,right=n-1;
        int index1=-1,index2=-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                if(mid==0)
                {
                    index1=mid;
                    break;
                }else if(nums[mid]!=nums[mid-1])
                {
                    index1=mid;
                    break;
                }else right=mid-1;
            }else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        
        left=0,right=n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                if(mid==n-1)
                {
                    index2=mid;
                    break;
                }else if(nums[mid]!=nums[mid+1])
                {
                    index2=mid;
                    break;
                }else left=mid+1;
            }else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        
        vector<int>result;
        result.push_back(index1);
        result.push_back(index2);
        
        return(result);
        
    }
};