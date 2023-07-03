class Solution {
public:
    int numIslands(vector<vector<char>>& num) {
    
    int n = num.size(), m = num[0].size();
    std::vector<std::vector<int>> inox(n, std::vector<int>(m, 0));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == '1' && inox[i][j] == 0)
            {
                count++;

                std::queue<std::pair<int, int>> temp;

                temp.push({i, j});
                inox[i][j] = 1;

                while (temp.size())
                {
                    int row = temp.front().first;
                    int col = temp.front().second;

                    temp.pop();

                    if (row - 1 >= 0 && inox[row - 1][col] == 0 && num[row - 1][col] == '1')
                    {
                        temp.push({row - 1, col});
                        inox[row - 1][col] = 1;
                    }

                    if (row + 1 < n && inox[row + 1][col] == 0 && num[row + 1][col] == '1')
                    {
                        temp.push({row + 1, col});
                        inox[row + 1][col] = 1;
                    }

                    if (col - 1 >= 0 && inox[row][col - 1] == 0 && num[row][col - 1] == '1')
                    {
                        temp.push({row, col - 1});
                        inox[row][col - 1] = 1;
                    }

                    if (col + 1 < m && inox[row][col + 1] == 0 && num[row][col + 1] == '1')
                    {
                        temp.push({row, col + 1});
                        inox[row][col + 1] = 1;
                    }
                }
            }
        }
    }

    return count;        
    }
};