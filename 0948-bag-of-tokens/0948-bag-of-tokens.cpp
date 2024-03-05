class Solution {
public:
    int bagOfTokensScore(vector<int>& num, int power) {

    int score = 0;
    ranges::sort(num);

    int start = 0, end = num.size() - 1;
    int max = 0;

    while (start <= end)
    {
        if (num[start] <= power)
            power -= num[start], score++,
                start++;
        else
        {
            if (score)
                power += num[end],
                    score--,
                    end--;
            else
                break;
        }

        max = std::max(max, score);
    }

    return max;
        
    }
};