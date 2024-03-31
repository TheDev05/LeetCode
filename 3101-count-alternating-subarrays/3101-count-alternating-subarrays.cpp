class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& num) {
        long long sum = num.size();
        
        for(int i = 0; i < num.size(); i++)
        {
            long long curr = i + 1, prev = i, count  = 1;
            while(curr < num.size() && num[curr] != num[prev])
            {
                count++;
                prev++;
                curr++;
            }
            
            i = prev;
            // std::cout<<count<<" ";
            sum += (count * (count - 1)) / 2;
        }
        
        return sum;
    }
};

// 0 1 1 1 0 0