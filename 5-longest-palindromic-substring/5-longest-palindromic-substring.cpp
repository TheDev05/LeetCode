class Solution {
public:
    string longestPalindrome(string s) {
        
    std::string text;
	text = s;

	if (text.size() == 1)
	{
		return(text);
	}

	int l = 0, r = 0;
	for (int i = 0; i < text.size() - 1; i++)
	{
		if (text[i] == text[i + 1])
		{
			int index1 = i;
			int index2 = i + 1;

			while (index1 >= 0 && index2 < text.size() && text[index1] ==                         text[index2] )
			{
				if ((index2 - index1) > (r - l))
				{
					l = index1;
					r = index2;
				}

				index1--;
				index2++;
			}
		}
	}

	for (int i = 0; i < text.size() - 2; i++)
	{
		if (text[i] == text[i + 2])
		{
			int index1 = i;
			int index2 = i + 2;

			while (index1 >= 0 && index2 < text.size()&& text[index1] ==                          text[index2])
			{
				if ((index2 - index1) > (r - l))
				{
					l = index1;
					r = index2;
				}

				index1--;
				index2++;
			}
		}
	}

	std::string result;
	for (int i = l; i <= r; i++)
	{
		result+= text[i];
	}
        
     return(result);
      
    }

    
};