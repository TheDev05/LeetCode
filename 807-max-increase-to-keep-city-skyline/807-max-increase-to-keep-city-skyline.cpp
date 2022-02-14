class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<int>data1;
        vector<int>data2;
        
       for(auto i: grid)
       {
           int max=INT_MIN;
           for(auto j:i)
           {
               max=std::max(max,j);
           }
           
           data1.push_back(max);
       }
        
        for(int i=0;i<grid.size();i++)
        {
            int max=INT_MIN;
            for(int j=0;j<grid[i].size();j++)
            {
                max=std::max(max,grid[j][i]);
            }
            
            data2.push_back(max);
        }
        
        
        int sum=0;
        vector<vector<int>>inox;
        
        for(auto i: data1)
        {
            vector<int>temp;
            for(auto j:data2)
            {
                temp.push_back(std::min(i,j));
            }
            
            inox.push_back(temp);
            
        }
        
         for(int i=0;i<grid.size();i++)
         {
        
            for(int j=0;j<grid[i].size();j++)
            {
                 sum+=abs(grid[i][j]-inox[i][j]);
            }
            
        }
        
        
        return(sum);
            
        
    }
};