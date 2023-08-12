class Solution {
public:
    bool isBipartite(vector<vector<int>>& num) {
    
    int n = num.size();
        
    std::vector<int> inox(n, -1);
    std::queue<int> temp;

    int color = 0;

    for(int i = 0 ; i < n; i++)
    {
        if(inox[i] == -1)
        {
            temp.push(i);
            inox[i] = color; 
            
            while (temp.size())
            {
                int local = temp.front();
                temp.pop();

                for (auto i : num[local])
                {
                    if (inox[i] == -1)
                    {
                        inox[i] = (inox[local]) ? 0 : 1;                
                        temp.push(i);
                    }
                }
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            if (inox[num[i][j]] == inox[i])
                ok = false;
        }
    }
        
    return ok;        
    }
};