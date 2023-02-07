class Solution {
public:
    int findMaxForm(vector<string>& num, int a, int b) {
           std::vector<std::pair<int, int>> data;
    for (auto i : num)
    {
        int zero = 0, one = 0;
        for (auto j : i)
        {
            if (j == '0')
                zero++;
            else
                one++;
        }

        data.push_back({zero, one});
    }

    std::vector<std::vector<std::vector<int>>> storage(num.size() + 1, std::vector<std::vector<int>>(a + 1, std::vector<int>(b + 1, 0)));
    // std::cout << getCount(data, storage, a, b, 0);

    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < a + 1; j++)
        {
            for (int k = 0; k < b + 1; k++)
            {
                int val1 = 0, val2 = 0;
                if (data[i].first <= j && data[i].second <= k)
                    val1 = 1 + storage[i + 1][j - data[i].first][k - data[i].second];
                val2 = storage[i + 1][j][k];

                storage[i][j][k] = std::max(val1, val2);
            }
        }
    }

    return storage[0][a][b]; 
    }
};