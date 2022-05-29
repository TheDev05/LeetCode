// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        // Your code goes here
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(a[mid]==1)
            {
                if(mid==0)return(mid);
                else if(a[mid-1]==0)return(mid);
                else right=mid-1;
            }else 
            {
                left=mid+1;
            }
        }
        
        return(-1);
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}  // } Driver Code Ends