class Solution {
public:
    int maxArea(vector<int>& height) {
        
        vector<int>num;
        num=height;
        
        int max = INT_MIN,n=num.size();
 	   for (int i = 0; i < n; i++)
	   {
		for (int j = 0; j < i; j++)
		{
			if (num[j] >= num[i])
			{
				max = std::max(max, (i - j) * num[i]);
				break;
			}
		}

		for (int k = n - 1; k > i; k--)
		{
			if (num[k] >= num[i])
			{
				max = std::max(max, (k - i) * num[i]);
				break;
			}
		}
	}
       
        return(max);
        
    }
};