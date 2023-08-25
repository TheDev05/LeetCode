class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        std::vector<int>num[n];
        for(int i=0;i<edges.size();i++)
            num[edges[i][0]].push_back(edges[i][1]);
        
        std::vector<int>indeg(n,0);
        for(int i=0;i<n;i++)
            for(auto j: num[i]) indeg[j]++;
        
        std::vector<int>res;
        for(int i=0;i<n;i++)if(indeg[i] == 0)res.push_back(i);
        
        return res;
            
    }
};