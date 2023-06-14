class Solution {

public:

    int lengthOfLongestSubstring(string s) {

        

        std::string text=s;

        set<int>data;

        

        int count=0,index=0;

        for(int i=0;i<text.size();i++)

        {

            

            if(data.size()>count)count=data.size();

            if(data.count(text[i]))

            {

                while(data.count(text[i]))

                {

                    data.erase(text[index]);

                    index++;

                }

            }

            

            data.insert(text[i]);

            if(data.size()>count)count=data.size();

        }

        

        return(count);

        

    }

};