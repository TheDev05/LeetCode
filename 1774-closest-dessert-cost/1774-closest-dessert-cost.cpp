class Solution {
public:
    int getCount(std::vector<int> &num, int sum, int target, int &result, int &min, int index, int local)
{
    if (abs(target - sum) <= min)
    {
        if (abs(target - sum) == min)
            result = std::min(result, sum);
        else
            result = sum;
            
        min = abs(target - sum);
    }

    if (index >= num.size() || sum >= target)
        return 0;

    if (sum < target)
    {
        for (int i = local; i < 2; i++)
        {
            sum += num[index];
            getCount(num, sum, target, result, min, index, local + 1);
            sum -= num[index];
        }
    }

    getCount(num, sum, target, result, min, index + 1, 0);

    return 0;
}


    int closestCost(vector<int>& num1, vector<int>& num2, int k) {
 
    int min = INT_MAX, result = 0;
    for (int i = 0; i < num1.size(); i++)
    {
        getCount(num2, num1[i], k, result, min, 0, 0);
    }

    return result;

    }
};