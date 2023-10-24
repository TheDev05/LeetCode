class Solution {
public:
void traverse(std::vector<std::string> &num, int &index)
{
    if (index >= num.size())
        return;

    if (num[index] == "#")
        return;

    for (int i = 0; i < 2; i++)
    {
        index = index + 1;
        traverse(num, index);
    }
}
    
    bool isValidSerialization(string text) {
        
    std::vector<std::string> num;
    std::string temp;
        
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ',')
        {
            num.push_back(temp);
            temp.clear();
        }
        else
            temp += text[i];

        if (i == text.size() - 1)
            num.push_back(temp);
    }


    int index = 0;
    traverse(num, index);

    if(index != num.size() - 1) return false;
    return true;
        
    }
};