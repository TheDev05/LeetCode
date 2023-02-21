class Solution {
public:
    int longestPalindromeSubseq(string text1) {
    std::string text2, result;

    text2 = text1;
    reverse(text2.begin(), text2.end());

    std::vector<std::vector<int>> storage(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    for (int i = storage.size() - 2; i >= 0; i--)
    {
        for (int j = storage[0].size() - 2; j >= 0; j--)
        {
            int val1 = 0, val2 = 0;
            if (text1[i] == text2[j])
                val1 = 1 + storage[i + 1][j + 1];
            else
                val2 = std::max(storage[i][j + 1], storage[i + 1][j]);

            storage[i][j] = std::max(val1, val2);
        }
    }

    return storage[0][0];        
    }
};