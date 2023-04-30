class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string text) {
        
        std::vector<std::string>result;
        for(int i=0;i<words.size();i++)
        {
            std::map<char,char>data1,data2;
            bool ok = true;
            
            for(int j=0;j<words[i].size();j++)
            {
                if(data1.count(words[i][j]))
                    {if(data1[words[i][j]] != text[j]) ok=false;}
                else data1[words[i][j]] = text[j];
            }
            
            for(int j=0;j<text.size();j++)
            {
                if(data2.count(text[j]))
                    {if(data2[text[j]] != words[i][j]) ok=false;}
                else data2[text[j]] = words[i][j];
            }
            
            if(ok) result.push_back(words[i]);
        }
        
        return result;
    }
};