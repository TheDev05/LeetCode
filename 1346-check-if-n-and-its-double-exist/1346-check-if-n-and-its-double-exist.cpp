class Solution {
public:
    
    bool BS(vector<int>num,int index, int key)
    {
        int left=index,right=num.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(num[mid]==key)return(true);
            else if(num[mid]>key)right=mid-1;
            else left=mid+1;
        }
        return(false);
    }
    
    bool checkIfExist(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1;i++)
        {
            if(arr[i]==0)
            {
                if(arr[i+1]==0)return(true);
                else continue;
            }
            
            int key=arr[i]*2;
            if(BS(arr,0, key))
                return(true);
        }
        
        return(false);
        
    }
};