class Solution
	{
	public:
		int search(vector<int> &nums, int target)
		{
    
			int n = nums.size(), index;
            
            if(n==1)
            {
                if(nums[0]==target)return(0);else return(-1);
            }
            
			int left = 0, right = n - 1;

			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (mid == 0)
				{
					if (nums[mid] < nums[mid + 1])
					{
						index = mid;
						break;
					}
					else
						left = mid + 1;
				}
				else if (mid == n - 1)
				{
					if (nums[mid] < nums[mid - 1])
					{
						index = mid;
						break;
					}
					else
						right = mid - 1;
				}else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1])
                {
		    	    index = mid;
                    break;
	        	}
				else if (nums[left] > nums[mid])
				{
					right = mid - 1;
				}
				else if (nums[mid] > nums[right])
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
            
            
			left = 0;
			right = index-1;

			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
				{
					return (mid);
				}
				else if (nums[mid] > target)
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}

			left = index;
			right = n - 1;

			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
				{
					return (mid);
				}
				else if (nums[mid] > target)
				{
					right = mid - 1;
				}
				else
					left = mid + 1;
			}

			return (-1);
		}
	};