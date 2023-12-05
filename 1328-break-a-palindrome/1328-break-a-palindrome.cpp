class Solution {
public:
    string breakPalindrome(string text) {

    if (text.size() == 1)
        return "";

    bool ok = true;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] > 'a')
        {
            if ((text.size() & 1) && (i == (text.size() / 2))) {}
            else
            {
                text[i] = 'a', ok = false;
                break;
            }
        }
    }

    if (ok)
        text[text.size() - 1] = 'b';

    return text;     
    }
};