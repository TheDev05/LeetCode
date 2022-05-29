class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return(nums[0]);
        
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int right_sum,left_sum;
            
            if(mid==0)
            {
                if(nums[mid]!=nums[mid+1])return(nums[mid]);
                else left=mid+1;
            }else if(mid==n-1)
            {
                if(nums[mid]!=nums[mid-1])return(nums[mid]);
                else right=mid-1;
            }else if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return(nums[mid]);
            else if(nums[mid]==nums[mid+1])
            {
                 right_sum=((n-1)-mid)+1;
                left_sum=((mid+1)-0)+1;
                
                if(right_sum&1)left=mid+2;
                else right=mid-1;
            }
            else if(nums[mid]==nums[mid-1])
            {
                 right_sum=((n-1)-(mid-1))+1;
                left_sum=(mid-0)+1;
                
                if(right_sum&1)left=mid+1;
                else right=mid-2;
                    
            }
               
        }
    return(0);
    }
    
};