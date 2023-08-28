class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& num) {
        
    int n = num.size(), m = num[0].size();

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> res;

    int r[4] = {0, 0, 1, -1};
    int c[4] = {1, -1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] && vis[i][j] == 0)
            {
                std::queue<std::pair<int, int>> inox;
                std::set<std::pair<int, int>> data;

                inox.push({i, j});
                vis[i][j] = 1;

                while (inox.size())
                {
                    int row = inox.front().first;
                    int col = inox.front().second;
                    inox.pop();

                    data.insert({row, col});
                    for (int k = 0; k < 4; k++)
                    {
                        int trow = row + r[k];
                        int tcol = col + c[k];

                        if (trow >= 0 && tcol >= 0 && trow < n && tcol < m && vis[trow][tcol] == 0 && num[trow][tcol])
                        {
                            inox.push({trow, tcol});
                            vis[trow][tcol] = 1;
                        }
                    }
                }

                std::vector<int> temp;
                temp.push_back(data.begin()->first);
                temp.push_back(data.begin()->second);

                temp.push_back(data.rbegin()->first);
                temp.push_back(data.rbegin()->second);

                res.push_back(temp);
            }
        }
    } 
        
    return res;
        
    }
};