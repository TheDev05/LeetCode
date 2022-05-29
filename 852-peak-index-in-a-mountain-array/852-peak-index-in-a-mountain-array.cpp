class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
                
        int n=arr.size();
        int left=0,right=n-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(mid==0)
            { if(arr[mid]>arr[mid+1]) return(mid );
                   else left=mid+1;  }
            else if(mid==n-1)   
                 {     if(arr[mid]>arr[mid-1])return(mid);
                   else right=mid-1;}
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return(mid);
            else if(arr[mid]<arr[mid+1])left=mid+1;
            else right=mid-1;
        }
        
        return(0);
    }
};