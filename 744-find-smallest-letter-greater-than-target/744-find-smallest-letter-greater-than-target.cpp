class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int left=0,right=(letters.size())-1;
        while(left<=right)
        {
            int mid=left+((right-left)/2);
            if(letters[mid]>target)right=mid-1;
            else left=mid+1;
        }
        
        char inox;
        if(right<=letters.size()-1 && letters[right]>target)
            inox=letters[right];
        else if((left>=0) && (letters[left]>target))
            inox=letters[left];
        else inox=letters[0];
       
        return(inox);
        
    }
};