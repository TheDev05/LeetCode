class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        
        std::map<int,int>store;
        for(int i=0;i<nums.size();i++)
        {
            store[nums[i]]++;
            
            int sum=0;
            while(nums[i])
            {
                int rem=nums[i]%10;
                nums[i]/=10;
                
                sum=(sum*10)+rem;
            }
            
            store[sum]++;
        }
        
        return store.size();
    }
};