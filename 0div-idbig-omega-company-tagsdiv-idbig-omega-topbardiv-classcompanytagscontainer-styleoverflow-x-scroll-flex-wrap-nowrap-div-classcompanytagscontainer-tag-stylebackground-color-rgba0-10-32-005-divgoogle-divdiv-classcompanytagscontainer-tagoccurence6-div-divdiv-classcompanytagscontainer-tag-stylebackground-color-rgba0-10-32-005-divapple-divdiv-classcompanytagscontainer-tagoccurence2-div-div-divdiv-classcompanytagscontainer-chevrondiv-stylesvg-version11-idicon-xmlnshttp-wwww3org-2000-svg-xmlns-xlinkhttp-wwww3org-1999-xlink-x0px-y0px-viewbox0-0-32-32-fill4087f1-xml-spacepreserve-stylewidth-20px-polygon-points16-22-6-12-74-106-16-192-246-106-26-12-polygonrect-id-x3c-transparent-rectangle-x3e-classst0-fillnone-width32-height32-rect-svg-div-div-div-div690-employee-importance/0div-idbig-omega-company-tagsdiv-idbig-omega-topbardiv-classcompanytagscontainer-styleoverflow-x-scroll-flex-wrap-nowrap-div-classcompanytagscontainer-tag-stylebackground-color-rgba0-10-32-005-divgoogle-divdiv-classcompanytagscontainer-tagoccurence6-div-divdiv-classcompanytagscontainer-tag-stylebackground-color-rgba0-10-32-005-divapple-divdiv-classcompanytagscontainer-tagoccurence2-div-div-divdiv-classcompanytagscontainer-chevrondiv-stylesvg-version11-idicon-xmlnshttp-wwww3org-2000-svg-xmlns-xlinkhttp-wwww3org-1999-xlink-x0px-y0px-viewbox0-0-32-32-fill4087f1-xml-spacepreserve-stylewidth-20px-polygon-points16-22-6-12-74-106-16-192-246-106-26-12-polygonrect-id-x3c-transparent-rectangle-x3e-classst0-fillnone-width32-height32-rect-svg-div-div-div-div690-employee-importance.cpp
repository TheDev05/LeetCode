/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        std::vector<int>imp(2000+1,0);
        std::vector<int>num[2000+1];
        for(auto i: employees)
        {
            imp[i->id] = i->importance;
            for(auto j: i->subordinates)
               num[i->id].push_back(j);     
        }
        
        std::vector<int>vis(2000+1,0);
        std::queue<int>inox;
        
        inox.push(id);
        vis[id]=1;
        
        int sum=0;
        while(inox.size())
        {
            auto it=inox.front();
            inox.pop();
            
            sum+=imp[it];
            
            for(auto i: num[it])
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    inox.push(i);
                }
            }
        }
        
        return sum;
        
    }
};