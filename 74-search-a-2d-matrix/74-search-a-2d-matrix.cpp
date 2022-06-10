class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int left=0;
        int right=(n*m)-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(matrix[mid/m][mid%m]==target)
                return(true);
            else if(matrix[mid/m][mid%m]>target)
            {
                if((mid/m==0) && (mid%m==0))return(false);
                else right=mid-1;
            }
            else {
                if((mid/m==n-1) && (mid%m==m-1))return(false);
                else left=mid+1;
            }
        }
        
        return(false);
    }
};