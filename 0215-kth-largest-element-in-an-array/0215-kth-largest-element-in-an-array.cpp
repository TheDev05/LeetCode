class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int>num;
        for(auto i: nums) num.push(i);
        
        int count = 0, inox = 0;
        while(num.size() && count < k)
        {
            inox = num.top();
            num.pop();
            
            count++;
        }
        
        return inox;
            
    }
};