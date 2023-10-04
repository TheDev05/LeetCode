class Solution {
public:
    bool canMakeSubsequence(string text1, string text2) {
        
    int index = 0;
    for (int i = 0; i < text1.size(); i++)
    {
        char toggle = text1[i];
        if (text1[i] == 'z')
            toggle = 'a';
        else
            toggle++;

        if (index < text2.size() && text1[i] == text2[index] || toggle == text2[index])
            index++;
    }

    if (index >= text2.size())
        return true;

        return false;
    }
};