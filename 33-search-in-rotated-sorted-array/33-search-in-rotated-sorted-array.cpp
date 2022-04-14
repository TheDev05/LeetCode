class Solution {
public:
    int search(vector<int>& nums, int target) {
    
        map<int,int>data;
        int index=0;
        
        for(auto i: nums)
        {
            data[i]=index;
           index++;    
        }
        
        if(data.count(target)==false)return(-1);
        else return(data[target]);
    
    }
};