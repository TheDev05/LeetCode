class Solution {
public:
    bool checkIfCanBreak(string text1, string text2) {
        
    sort(text1.begin(), text1.end());
    sort(text2.begin(), text2.end());

    bool ok1 = true, ok2 = true;
    for (int i = 0; i < text1.size(); i++)
    {
        if (text1[i] < text2[i])
            ok1 = false;
        if (text1[i] > text2[i])
            ok2 = false;
    }

    if (ok1 || ok2)
        return true;
    
    return false;
    }
};