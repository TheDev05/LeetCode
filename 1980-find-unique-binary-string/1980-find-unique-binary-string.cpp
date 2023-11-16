class Solution {
public:
std::string traverse(std::set<std::string> &exist, std::string &temp)
{
    if (temp.size() == exist.size())
    {
        if (exist.contains(temp) == false)
            return temp;

        return "";
    }

    temp += "0";
    std::string res1 = traverse(exist, temp);
    temp.erase(temp.size() - 1);

    if(res1.size()) return res1;

    temp += "1";
    std::string res2 = traverse(exist, temp);
    temp.erase(temp.size() - 1);

    if(res2.size()) return res2;

    return "";
}
    
    string findDifferentBinaryString(vector<string>& num) {
    std::set<std::string> exist;
    for (auto i : num)
        exist.insert(i);

    std::string temp;
    return traverse(exist, temp);        
    }
};