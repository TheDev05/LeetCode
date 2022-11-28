class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>lostOnlyOne;
        vector<int>winners;
        
       for(int i=0;i<matches.size();i++)
       {
           winners.push_back(matches[i][0]);
           lostOnlyOne[matches[i][1]]++;
           
       }
        
        set<int>temp1,temp2;
        for(auto i: lostOnlyOne)
        {
            if(i.second==1)
            {
              temp2.insert(i.first);
            }
        }
        
        for(auto i: winners)
        {
            if(!lostOnlyOne.count(i))temp1.insert(i);
        }
        
        vector<int>inox1,inox2;
        for(auto i: temp1)
        {
            inox1.push_back(i);
        }
        
        for(auto i: temp2)
        {
            inox2.push_back(i);
        }
        
        vector<vector<int>>result;
        
        result.push_back(inox1);
        result.push_back(inox2);

        return result;
    }
};