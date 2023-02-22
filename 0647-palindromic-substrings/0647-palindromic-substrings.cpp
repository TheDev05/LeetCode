class Solution {
public:
    int countSubstrings(string text) {
    std::vector<std::vector<int>> storage(text.size(), std::vector<int>(text.size(), -1));

    int inox = 0, count = 0;
    for (int i = 0; i < text.size(); i++)
    {
        int row = 0, col = inox;
        while (row < text.size() && col < text.size())
        {
            bool ok = true;
            if (text[row] != text[col])
                ok = false;
            if (row < text.size() - 1 && col > 0 && storage[row + 1][col - 1] == 0)
                ok = false;

            if (ok)
                storage[row][col] = 1;
            else
                storage[row][col] = 0;

            if (storage[row][col] == 1)
                count++;

            row++;
            col++;
        }

        inox++;
    }

    return count;        
    }
};