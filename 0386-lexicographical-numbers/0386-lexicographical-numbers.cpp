class Solution {
public:
int traverse(int temp, int n, std::vector<int> &num)
{
    if (temp > n)
        return 0;

    num.push_back(temp);
    for (int i = 0; i < 10; i++)
    {
        traverse((temp * 10) + i, n, num);
    }

    return 1;
}
    
    vector<int> lexicalOrder(int n) {
        
    std::vector<int> num;
    for (int i = 1; i < 10; i++)
    {
        traverse(i, n, num);
    }
        
    return num;
    }
};