class Solution {
public:
    string frequencySort(string s) {
        map<char,int>data;
        for(auto i: s)
        {
            data[i]++;
        }
        
        std::vector<pair<int,char>>num;
        for(auto i: data)
        {
            num.push_back(make_pair(-i.second,i.first));
        }
        
        sort(num.begin(),num.end());
        
        std::string text;
        for(auto j: num)
        {
            for(int i=0;i<abs(j.first);i++)
            {
                text+=j.second;
            }
        }
        
        return(text);
        
        
    }
};