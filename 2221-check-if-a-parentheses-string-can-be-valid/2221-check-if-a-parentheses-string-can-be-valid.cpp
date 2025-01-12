class Solution {
public:
    bool canBeValid(string text, string temp) {

    int left = 0, right = 0;
    if (text.size() & 1)
        return false;

    int lock = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (temp[i] == '0')
            left++;
        else if (text[i] == ')')
        {
            if (left)
                left--;
            else if (lock)
                lock--;
            else
                return false;
        }
        else
            lock++;
    }

    lock = 0;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        if (temp[i] == '0')
            right++;
        else if (text[i] == '(')
        {
            if (right)
                right--;
            else if (lock)
                lock--;
            else
                return false;
        }
        else
            lock++;
    }
    
    return true; 

    }
};