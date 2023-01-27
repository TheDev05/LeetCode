class Solution {
public:
int getCount(std::string &text1, std::string &text2, std::vector<std::vector<int>> &storage, int index1, int index2)
{
    if (index2 >= text2.size())
        return 1;
    else if (index1 >= text1.size())
        return 0;

    if (storage[index1][index2] == -1)
    {
        int val1 = 0, val2 = 0;
        if (text1[index1] == text2[index2])
        {
            val1 = getCount(text1, text2, storage, index1 + 1, index2 + 1);
            val2 = getCount(text1, text2, storage, index1 + 1, index2);
        }
        else
            val2 = getCount(text1, text2, storage, index1 + 1, index2);

        storage[index1][index2] = (val1 + val2);
    }

    return storage[index1][index2];
}
    
    int numDistinct(string text1, string text2) {
    std::vector<std::vector<int>> storage(text1.size(), std::vector<int>(text2.size(), -1));
     return getCount(text1, text2, storage, 0, 0);
 
    }
};