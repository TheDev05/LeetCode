class Solution {
public:
    int removeAlmostEqualCharacters(string text) {
        
    int ans = 0;
    for (int i = 0; i < text.size(); i++)
    {
        int count = 0, index = i, prev = i;
        while ((text[prev] == text[index] || (count && abs(((char)text[index]) - ((char)text[index - 1])) == 1)) && index < text.size())
            prev = index, index++, count++;

        ans += count / 2;
        i = index - 1;
    }

        
        return ans;
    }
};