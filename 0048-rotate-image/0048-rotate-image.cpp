class Solution {
public:
    void rotate(vector<vector<int>>& num) {
    for (int i = 0; i < ceil((double)num.size() / 2); i++)
    {
        int topLeft_row = i, topLeft_col = i;
        int topRight_row = i, topRight_col = num.size() - 1 - i;

        int bottomLeft_row = num.size() - 1 - i,
            bottomLeft_col = i;

        int bottomRight_row = num.size() - 1 - i,
            bottomRight_col = num.size() - 1 - i;

        for (int j = 0; j < (num.size() - (i * 2) - 1); j++)
        {
            int temp1 = num[topLeft_row][topLeft_col + j];
            int temp2 = num[topRight_row + j][topRight_col];

            int temp3 = num[bottomRight_row][bottomRight_col - j];
            int temp4 = num[bottomLeft_row - j][bottomLeft_col];

            num[topLeft_row][topLeft_col + j] = temp4;
            num[topRight_row + j][topRight_col] = temp1;
            num[bottomRight_row][bottomRight_col - j] = temp2;
            num[bottomLeft_row - j][bottomLeft_col] = temp3;
        }
    }
    }
};

// 0,0* -> 0*,m-1 -> n-1,m-1-0*, -> n-1-0*,0 -> 0,0*
// 0,1 -> 1,m-1 -> n-1,m-1-1 -> n-1-1,0