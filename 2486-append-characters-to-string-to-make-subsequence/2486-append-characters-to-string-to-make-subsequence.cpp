class Solution {
public:
    int appendCharacters(string text1, string text2) {
        
    int index = 0;
    for (int i = 0; i < text1.size(); i++)
    {
        if (index < text2.size() && text1[i] == text2[index])
            index++;
    }

    return text2.size() - index;        
    }
};