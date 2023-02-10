class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        std::string text="";
        
        for(int i=0;i<std::min(strs[0].size(),strs[strs.size()-1].size());i++)
        {
            if(strs[0][i]==strs[strs.size()-1][i])
                text+=strs[0][i];
            else break;
        }
        
        return(text);
        
        
    }
};