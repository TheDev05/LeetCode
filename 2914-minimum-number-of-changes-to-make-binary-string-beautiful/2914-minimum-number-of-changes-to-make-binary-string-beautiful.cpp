class Solution {
public:
    int minChanges(string text) {
        
    char temp = text[0];
    int count = 0, res = 0;

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] != temp)
        {
            if (count & 1)
                res++, count = 0;
            else
                count = 1;

            temp = text[i];
        }
        else
            count++;
    }

    return res;        
    }
};