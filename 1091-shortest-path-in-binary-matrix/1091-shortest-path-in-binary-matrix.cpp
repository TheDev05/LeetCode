class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& num) {
    
    int n = num.size();
    std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));

    if(num[0][0] == 1) return -1;
        
    int count = 0;
    bool ok = false;

    std::queue<std::pair<int, int>> temp;

    temp.push({0, 0});
    visited[0][0] = 1;

    while (temp.size())
    {
        count++;
        int size = temp.size();

        for (int i = 0; i < size; i++)
        {
            int nrow = temp.front().first;
            int ncol = temp.front().second;

            temp.pop();

            if (nrow == n - 1 && ncol == n - 1)
            {
                ok = true;
                break;
            }

            for (int p = -1; p <= 1; p++)
            {
                for (int q = -1; q <= 1; q++)
                {
                    int trow = nrow + p;
                    int tcol = ncol + q;

                    if (trow >= 0 && trow < n && tcol >= 0 && tcol < n && num[trow][tcol] == 0 && visited[trow][tcol] == 0)
                    {
                        temp.push({trow, tcol});
                        visited[trow][tcol] = 1;
                    }
                }
            }
        }

        if (ok)
            break;
    }

    if (!ok)
        count = -1;

    return count;       
    }
};