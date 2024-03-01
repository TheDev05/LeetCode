class Solution {
public:
    bool isPrime(int N) 
    { 
        int ok = 1; 
        for (int i = 2; i <= N / 2; i++) { 

            if (N % i == 0) { 
                ok = 0; 
                break; 
            } 
        } 

        if (ok) 
           return 1;

        return 0; 
    } 
    

int traverse(std::vector<std::vector<int>> &num, std::map<int, int> &data, int row, int col)
{
    int res_row = row, res_col = col;

    int sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;

    while (row < num.size())
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row++;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (row >= 0)
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row--;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col >= 0)
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        col--;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col < num[0].size())
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        col++;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col >= 0 && row < num.size())
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row++;
        col--;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col < num[0].size() && row < num.size())
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row++;
        col++;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col >= 0 && row >= 0)
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row--;
        col--;
    }

    row = res_row, col = res_col;
    sum = 0;
    if (sum > 10 && isPrime(sum))
        data[sum]++;
    while (col < num[0].size() && row >= 0)
    {
        sum = (sum * 10) + num[row][col];
        if (sum > 10 && isPrime(sum))
            data[sum]++;

        row--;
        col++;
    }
    
    return 0;
}
    
    
        
    int mostFrequentPrime(vector<vector<int>>& num) {
    // fillPrime();
        
    std::map<int, int> data;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            traverse(num, data, i, j);
        }
    }

    int max = 0, res = -1;
    for (auto i : data)
        max = std::max(max, i.second);

    for (auto i : data)
        if (i.second == max)
            res = std::max(res, i.first);

    return res;        
    }
};