class Solution {
public:
int getCount(std::string text, std::vector<int> &num, std::vector<int> &result, int index)
{
    if (index >= text.size())
    {
        if (num.size() >= 3)
        {
            result = num;
            return 1;
        }

        return 0;
    }

    long long temp = 0;
    if (num.size() < 2)
    {
        for (int i = index; i < text.size(); i++)
        {
            temp = (temp * 10) + ((int)(text[i] - '0'));
            if (temp >= pow(2, 31))
                return 0;

            num.push_back(temp);
            if (getCount(text, num, result, i + 1))
                return 1;
            num.pop_back();

            if (temp == 0)
                return 0;
        }
    }
    else
    {
        long long sum = ((long long)num[num.size() - 1] + num[num.size() - 2]);
        for (int i = index; i < text.size(); i++)
        {
            temp = (temp * 10) + ((int)(text[i] - '0'));
            
            if (temp >= pow(2, 31))
                return 0;

            if (temp > sum)
                return 0;

            if (temp == sum)
            {
                num.push_back(temp);
                if (getCount(text, num, result, i + 1))
                    return 1;
                num.pop_back();
            }

            if (temp == 0)
                return 0;
        }
    }

    return 0;
}

    vector<int> splitIntoFibonacci(string text) {
    std::vector<int> num, result;
    getCount(text, num, result, 0);
    
    return result;
    }
};