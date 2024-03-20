class Solution {
public:
    int minimumLength(string text) {
        
    int start = 0, end = text.size() - 1, count = 0;
    while (start < end)
    {
        if (text[start] == text[end])
        {
            int index = start;
            while (index < end && text[start] == text[index])
            {
                index++;
                count++;
            }

            start = index;

            index = end;
            while (start <= index && text[end] == text[index])
            {
                index--;
                count++;
            }

            end = index;
        }
        else
            break;
    }

    return text.size() - count;
        
    }
};