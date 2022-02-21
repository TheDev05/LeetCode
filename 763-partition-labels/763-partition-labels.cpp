
	class Solution
	{
	public:
		vector<int> partitionLabels(string s)
		{
			std::string text = s;
			map<char, vector<int>> num;

			for (int i = 0; i < text.size(); i++)
			{
				num[text[i]].push_back(i);
			}

			vector<int> result;
			for (int i = 0; i < text.size(); i++)
			{
				int inox = num[text[i]].back(), count = 0;
				for (int j = 0; j <= inox; j++)
				{
					if (num[text[j]].back() > inox)
					{
						inox = num[text[j]].back();
					}

					count++;
				}
                
				result.push_back((inox-i)+1);
		        i=inox;
            }
            
			return (result);
		}
	};