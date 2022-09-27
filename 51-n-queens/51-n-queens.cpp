class Solution {
public:
    
int queens[100];
bool check(int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		int queensCol = queens[i];
		int queensRow = i;

		if (col == queensCol || abs(row - queensRow) == abs(col - queensCol))
		{
			return false;
		}
	}

	return true;
}

int fun(vector<vector<int>> &num,int n, vector<int> temp, int row)
{
	if (row == n)
	{
		num.push_back(temp);
		return (1);
	}

	int total = 0;
	for (int col = 0; col < n; col++)
	{
		if (check(col, row))
		{
			queens[row] = col;
			temp.push_back(col);

			total += fun(num,n,temp,row + 1);
			temp.pop_back();
			queens[row] = -1;
		}
	}

	return (total);
}
    
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> num;
	vector<int> temp;
        
    memset(queens,-1,sizeof(queens));

	fun(num,n, temp, 0);

	vector<string> data;
	for (int i = 0; i < n; i++)
	{
		std::string text;
		for (int j = 0; j < n; j++)
		{
			text += '.';
		}

		data.push_back(text);
	}
        

	vector<vector<string>> res;
	for (int i = 0; i < num.size(); i++)
	{
		vector<string>local=data;
		for (int j = 0; j < num[i].size(); j++)
		{
			local[j][num[i][j]] = 'Q';
		}

		res.push_back(local);
	}

	return (res);
    }
};