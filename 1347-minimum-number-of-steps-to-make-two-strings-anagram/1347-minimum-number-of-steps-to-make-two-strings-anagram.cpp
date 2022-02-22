
	class Solution
	{
	public:
		int minSteps(string s, string t)
		{
			std::string text = s;
			map<char, int> num;

			for (auto i : text)
				num[i]++;

			int count = 0;
			text = t;

			for (int i = 0; i < text.size(); i++)
			{
				if (num[text[i]])
				{
					num[text[i]]--;
                    if(num[text[i]]==0)num.erase(text[i]);
				}else count++;
			}

			return (count);
		}
	};